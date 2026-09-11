Bu-Ali Chess — Linux package
============================

Run:
  ./chess.sh

If the game fails to start because of missing Qt libraries, install the
runtime packages listed in INSTALL-DEPS.txt (Ubuntu/Debian), or rebuild a
portable package with linuxdeployqt / CQtDeployer:

  ./scripts/build-linux.sh
  ./scripts/package-linux.sh
