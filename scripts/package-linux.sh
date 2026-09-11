#!/usr/bin/env bash
# Create a fuller Linux package by copying linked Qt shared libraries
# and common QML modules next to the binary (best-effort portable folder).
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT}/build-release"
DIST_DIR="${ROOT}/dist/Bu-Ali-Chess-linux"
ZIP_OUT="${ROOT}/dist/Bu-Ali-Chess-linux.zip"
QT_LIB_DIR="/usr/lib/x86_64-linux-gnu"
QT_QML_DIR="/usr/lib/x86_64-linux-gnu/qt5/qml"
QT_PLUGINS_DIR="/usr/lib/x86_64-linux-gnu/qt5/plugins"

if [[ ! -x "${BUILD_DIR}/chess" ]]; then
  "${ROOT}/scripts/build-linux.sh"
fi

rm -rf "${DIST_DIR}"
mkdir -p "${DIST_DIR}/bin" "${DIST_DIR}/lib" "${DIST_DIR}/plugins/platforms" \
  "${DIST_DIR}/plugins/imageformats" "${DIST_DIR}/plugins/mediaservice" \
  "${DIST_DIR}/qml"

cp "${BUILD_DIR}/chess" "${DIST_DIR}/bin/chess"
chmod +x "${DIST_DIR}/bin/chess"
cp "${ROOT}/media/knight2.png" "${DIST_DIR}/bu-ali-chess.png"
cp "${ROOT}/packaging/linux/bu-ali-chess.desktop" "${DIST_DIR}/"
cp "${ROOT}/packaging/linux/README-RUN.txt" "${DIST_DIR}/README.txt"

# Copy direct + recursive NEEDED libs that look Qt/related
copy_deps() {
  local bin="$1"
  ldd "${bin}" | awk '/=>/ {print $3}' | while read -r so; do
    [[ -z "${so}" || "${so}" == "not" ]] && continue
    base="$(basename "${so}")"
    case "${base}" in
      libQt5*|libicu*|libpcre2-16*|libdouble-conversion*|libmd4c*|libxcb-*|libxkbcommon*)
        cp -f "${so}" "${DIST_DIR}/lib/" 2>/dev/null || true
        ;;
    esac
  done
}

copy_deps "${DIST_DIR}/bin/chess"

# Platform + image + multimedia plugins
for f in libqxcb.so; do
  [[ -f "${QT_PLUGINS_DIR}/platforms/${f}" ]] && cp "${QT_PLUGINS_DIR}/platforms/${f}" "${DIST_DIR}/plugins/platforms/"
done
for f in libqjpeg.so libqgif.so libqsvg.so; do
  [[ -f "${QT_PLUGINS_DIR}/imageformats/${f}" ]] && cp "${QT_PLUGINS_DIR}/imageformats/${f}" "${DIST_DIR}/plugins/imageformats/"
done
if [[ -d "${QT_PLUGINS_DIR}/mediaservice" ]]; then
  cp -a "${QT_PLUGINS_DIR}/mediaservice/"*.so "${DIST_DIR}/plugins/mediaservice/" 2>/dev/null || true
fi
if [[ -d "${QT_PLUGINS_DIR}/audio" ]]; then
  mkdir -p "${DIST_DIR}/plugins/audio"
  cp -a "${QT_PLUGINS_DIR}/audio/"*.so "${DIST_DIR}/plugins/audio/" 2>/dev/null || true
fi

# QML modules used by the app
for mod in QtQuick QtQuick.2 QtQml QtMultimedia QtGraphicalEffects \
           QtQuick/Controls.2 QtQuick/Controls.2/Material QtQuick/Layouts \
           QtQuick/Templates.2 QtQuick/Window.2; do
  src="${QT_QML_DIR}/${mod}"
  if [[ -e "${src}" ]]; then
    mkdir -p "${DIST_DIR}/qml/$(dirname "${mod}")"
    cp -a "${src}" "${DIST_DIR}/qml/$(dirname "${mod}")/"
  fi
done

# Extra Qt libs often needed by plugins/QML (not always in ldd of main binary)
for lib in \
  libQt5DBus.so.5 libQt5Svg.so.5 libQt5XcbQpa.so.5 \
  libQt5QuickTemplates2.so.5 libQt5QmlWorkerScript.so.5 \
  libQt5MultimediaQuick.so.5 libQt5MultimediaGstTools.so.5 \
  libQt5MultimediaWidgets.so.5 libQt5OpenGL.so.5
 do
  [[ -f "${QT_LIB_DIR}/${lib}" ]] && cp -f "${QT_LIB_DIR}/${lib}" "${DIST_DIR}/lib/" || true
done

# Also pull deps of copied Qt libs / plugins
find "${DIST_DIR}/lib" "${DIST_DIR}/plugins" -type f -name '*.so*' 2>/dev/null | while read -r f; do
  copy_deps "${f}" || true
done

cat > "${DIST_DIR}/bin/qt.conf" <<'EOF'
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

cat > "${DIST_DIR}/INSTALL.txt" <<'EOF'
Bu-Ali Chess — Linux distribution

1) Extract this folder anywhere.
2) Run:  ./chess.sh

Requirements on the target PC:
- A normal 64-bit Linux desktop (X11/Wayland with XWayland)
- Basic system libraries (glibc, libstdc++, OpenGL/EGL/X11) — usually already present

If audio fails, install GStreamer plugins on the system:
  sudo apt install gstreamer1.0-plugins-good gstreamer1.0-plugins-base

This package bundles Qt5 libraries and QML modules used by the game.
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
