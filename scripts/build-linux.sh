#!/usr/bin/env bash
# Build Bu-Ali Chess (Linux)
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT}/build-release"
GENERATOR="${GENERATOR:-Unix Makefiles}"
JOBS="${JOBS:-$(nproc 2>/dev/null || echo 2)}"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

if command -v qmake >/dev/null 2>&1 || command -v qmake-qt5 >/dev/null 2>&1; then
  QMAKE_BIN="$(command -v qmake-qt5 || command -v qmake)"
  echo "==> Building with qmake (${QMAKE_BIN})"
  "${QMAKE_BIN}" "${ROOT}/chess.pro" -spec linux-g++ CONFIG+=release
  make -j"${JOBS}"
  echo "==> Binary: ${BUILD_DIR}/chess"
elif command -v cmake >/dev/null 2>&1; then
  echo "==> Building with CMake"
  cmake -S "${ROOT}" -B "${BUILD_DIR}" -G "${GENERATOR}" -DCMAKE_BUILD_TYPE=Release
  cmake --build "${BUILD_DIR}" -j"${JOBS}"
  echo "==> Binary: ${BUILD_DIR}/chess"
else
  echo "Error: need qmake (Qt5) or cmake + Qt5 packages." >&2
  exit 1
fi
