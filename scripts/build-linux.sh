#!/usr/bin/env bash
# Build Bu-Ali Chess (prefers Qt 6, falls back to Qt 5)
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT}/build-release"
JOBS="${JOBS:-$(nproc 2>/dev/null || echo 2)}"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

QMAKE_BIN=""
if command -v qmake6 >/dev/null 2>&1; then
  QMAKE_BIN="$(command -v qmake6)"
elif [[ -x /usr/lib/qt6/bin/qmake ]]; then
  QMAKE_BIN=/usr/lib/qt6/bin/qmake
elif command -v qmake-qt5 >/dev/null 2>&1; then
  QMAKE_BIN="$(command -v qmake-qt5)"
elif command -v qmake >/dev/null 2>&1; then
  QMAKE_BIN="$(command -v qmake)"
fi

if [[ -n "${QMAKE_BIN}" ]]; then
  echo "==> Building with qmake (${QMAKE_BIN})"
  "${QMAKE_BIN}" -v || true
  "${QMAKE_BIN}" "${ROOT}/chess.pro" -spec linux-g++ CONFIG+=release
  make -j"${JOBS}"
  echo "==> Binary: ${BUILD_DIR}/chess"
  exit 0
fi

if command -v cmake >/dev/null 2>&1; then
  echo "==> Building with CMake (Qt6 preferred, Qt5 fallback)"
  cmake -S "${ROOT}" -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE=Release
  cmake --build "${BUILD_DIR}" -j"${JOBS}"
  echo "==> Binary: ${BUILD_DIR}/chess"
  exit 0
fi

echo "Error: need qmake6/qmake or cmake + Qt packages." >&2
exit 1
