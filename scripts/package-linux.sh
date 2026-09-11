#!/usr/bin/env bash
# Package Bu-Ali Chess for Linux (Qt 6 preferred, Qt 5 fallback)
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT}/build-release"
DIST_DIR="${ROOT}/dist/Bu-Ali-Chess-linux"
ZIP_OUT="${ROOT}/dist/Bu-Ali-Chess-linux.zip"
QT_LIB_DIR="/usr/lib/x86_64-linux-gnu"

if [[ ! -x "${BUILD_DIR}/chess" ]]; then
  "${ROOT}/scripts/build-linux.sh"
fi

# Detect Qt major from linked libs
QT_MAJOR=6
if ldd "${BUILD_DIR}/chess" 2>/dev/null | grep -q 'libQt5'; then
  QT_MAJOR=5
fi

if [[ "${QT_MAJOR}" -eq 6 ]]; then
  QT_QML_DIR="/usr/lib/x86_64-linux-gnu/qt6/qml"
  QT_PLUGINS_DIR="/usr/lib/x86_64-linux-gnu/qt6/plugins"
  QT_LIB_GLOB='libQt6*'
else
  QT_QML_DIR="/usr/lib/x86_64-linux-gnu/qt5/qml"
  QT_PLUGINS_DIR="/usr/lib/x86_64-linux-gnu/qt5/plugins"
  QT_LIB_GLOB='libQt5*'
fi

echo "==> Packaging for Qt ${QT_MAJOR}"

rm -rf "${DIST_DIR}"
mkdir -p "${DIST_DIR}/bin" "${DIST_DIR}/lib" "${DIST_DIR}/plugins/platforms" \
  "${DIST_DIR}/plugins/imageformats" "${DIST_DIR}/plugins/multimedia" \
  "${DIST_DIR}/qml"

cp "${BUILD_DIR}/chess" "${DIST_DIR}/bin/chess"
chmod +x "${DIST_DIR}/bin/chess"
cp "${ROOT}/media/knight2.png" "${DIST_DIR}/bu-ali-chess.png"
cp "${ROOT}/packaging/linux/bu-ali-chess.desktop" "${DIST_DIR}/"
cp "${ROOT}/packaging/linux/README-RUN.txt" "${DIST_DIR}/README.txt"

copy_deps() {
  local bin="$1"
  ldd "${bin}" 2>/dev/null | awk '/=>/ {print $3}' | while read -r so; do
    [[ -z "${so}" || "${so}" == "not" ]] && continue
    base="$(basename "${so}")"
    case "${base}" in
      libQt5*|libQt6*|libicu*|libpcre2-16*|libdouble-conversion*|libmd4c*|libxcb-*|libxkbcommon*|libb2*)
        cp -f "${so}" "${DIST_DIR}/lib/" 2>/dev/null || true
        ;;
    esac
  done
}

copy_deps "${DIST_DIR}/bin/chess"

for f in libqxcb.so libqoffscreen.so; do
  [[ -f "${QT_PLUGINS_DIR}/platforms/${f}" ]] && cp "${QT_PLUGINS_DIR}/platforms/${f}" "${DIST_DIR}/plugins/platforms/"
done
for f in libqjpeg.so libqgif.so libqsvg.so; do
  [[ -f "${QT_PLUGINS_DIR}/imageformats/${f}" ]] && cp "${QT_PLUGINS_DIR}/imageformats/${f}" "${DIST_DIR}/plugins/imageformats/"
done

if [[ -d "${QT_PLUGINS_DIR}/multimedia" ]]; then
  cp -a "${QT_PLUGINS_DIR}/multimedia/"*.so "${DIST_DIR}/plugins/multimedia/" 2>/dev/null || true
fi
if [[ -d "${QT_PLUGINS_DIR}/mediaservice" ]]; then
  mkdir -p "${DIST_DIR}/plugins/mediaservice"
  cp -a "${QT_PLUGINS_DIR}/mediaservice/"*.so "${DIST_DIR}/plugins/mediaservice/" 2>/dev/null || true
fi
if [[ -d "${QT_PLUGINS_DIR}/audio" ]]; then
  mkdir -p "${DIST_DIR}/plugins/audio"
  cp -a "${QT_PLUGINS_DIR}/audio/"*.so "${DIST_DIR}/plugins/audio/" 2>/dev/null || true
fi

if [[ "${QT_MAJOR}" -eq 6 ]]; then
  QML_MODS=(
    QtQuick QtQml QtMultimedia
    QtQuick/Controls QtQuick/Controls/Material QtQuick/Controls/impl
    QtQuick/Layouts QtQuick/Templates QtQuick/Window
    QtQml/Models QtQml/WorkerScript
  )
  EXTRA_LIBS=(
    libQt6DBus.so.6 libQt6Svg.so.6 libQt6XcbQpa.so.6
    libQt6QuickTemplates2.so.6 libQt6QmlWorkerScript.so.6
    libQt6MultimediaQuick.so.6 libQt6OpenGL.so.6
    libQt6LabsFolderListModel.so.6
  )
else
  QML_MODS=(
    QtQuick QtQuick.2 QtQml QtMultimedia QtGraphicalEffects
    QtQuick/Controls.2 QtQuick/Controls.2/Material QtQuick/Layouts
    QtQuick/Templates.2 QtQuick/Window.2
  )
  EXTRA_LIBS=(
    libQt5DBus.so.5 libQt5Svg.so.5 libQt5XcbQpa.so.5
    libQt5QuickTemplates2.so.5 libQt5QmlWorkerScript.so.5
    libQt5MultimediaQuick.so.5 libQt5OpenGL.so.5
  )
fi

for mod in "${QML_MODS[@]}"; do
  src="${QT_QML_DIR}/${mod}"
  if [[ -e "${src}" ]]; then
    mkdir -p "${DIST_DIR}/qml/$(dirname "${mod}")"
    cp -a "${src}" "${DIST_DIR}/qml/$(dirname "${mod}")/"
  fi
done

for lib in "${EXTRA_LIBS[@]}"; do
  [[ -f "${QT_LIB_DIR}/${lib}" ]] && cp -f "${QT_LIB_DIR}/${lib}" "${DIST_DIR}/lib/" || true
done

find "${DIST_DIR}/lib" "${DIST_DIR}/plugins" -type f -name '*.so*' 2>/dev/null | while read -r f; do
  copy_deps "${f}" || true
done

cat > "${DIST_DIR}/bin/qt.conf" <<EOF
[Paths]
Prefix= ./../
Libraries= ./lib/
Plugins= ./plugins/
Imports= ./qml/
Qml2Imports= ./qml/
EOF

cat > "${DIST_DIR}/chess.sh" <<'EOF'
#!/usr/bin/env bash
BASE_DIR="$(cd "$(dirname "$(readlink -f "$0")")" && pwd)"
export LD_LIBRARY_PATH="${BASE_DIR}/lib:${LD_LIBRARY_PATH:-}"
export QML2_IMPORT_PATH="${BASE_DIR}/qml:${QML2_IMPORT_PATH:-}"
export QML_IMPORT_PATH="${BASE_DIR}/qml:${QML_IMPORT_PATH:-}"
export QT_PLUGIN_PATH="${BASE_DIR}/plugins:${QT_PLUGIN_PATH:-}"
export QT_QPA_PLATFORM_PLUGIN_PATH="${BASE_DIR}/plugins/platforms"
export QT_QPA_PLATFORM="${QT_QPA_PLATFORM:-xcb}"
exec "${BASE_DIR}/bin/chess" "$@"
EOF
chmod +x "${DIST_DIR}/chess.sh"

cat > "${DIST_DIR}/INSTALL.txt" <<EOF
Bu-Ali Chess — Linux distribution (Qt ${QT_MAJOR})

1) Extract this folder anywhere.
2) Run:  ./chess.sh

Needs a normal 64-bit Linux desktop (X11 or Wayland/XWayland).
For audio (optional):
  sudo apt install gstreamer1.0-plugins-good gstreamer1.0-libav libpulse0
EOF

mkdir -p "${ROOT}/dist"
(
  cd "${ROOT}/dist"
  rm -f Bu-Ali-Chess-linux.zip
  zip -r Bu-Ali-Chess-linux.zip Bu-Ali-Chess-linux >/dev/null
)

echo "==> Portable package:"
echo "    ${DIST_DIR}"
echo "    ${ZIP_OUT}"
du -sh "${DIST_DIR}" "${ZIP_OUT}"
