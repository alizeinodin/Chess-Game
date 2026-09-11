# Bu-Ali Chess

Chess game project for the advanced programming course at Bu-Ali Sina University.

C++ backend + QML/JavaScript frontend (Qt Quick, Material style).

**Score:** 173/100

## Features

- OOP chess engine (moves, check/mate, castling, en passant, promotion, undo)
- Save/load game data via `.acd` files
- Qt Quick UI with animations and sound

## Requirements

See **[INSTALL.md](INSTALL.md)** (Persian + detailed steps).

Short version:

- **Qt 5.12–5.15** with Quick, Quick Controls 2, Multimedia
- C++11 compiler (g++ / MinGW / MSVC)

### Ubuntu / Debian (dev packages)

```bash
sudo apt install -y build-essential cmake qt5-qmake qtbase5-dev \
  qtdeclarative5-dev qtquickcontrols2-5-dev qtmultimedia5-dev \
  libqt5multimedia5-plugins qml-module-qtquick-controls2 \
  qml-module-qtmultimedia qml-module-qtquick-layouts \
  qml-module-qtgraphicaleffects
```

## Build

```bash
chmod +x scripts/*.sh
./scripts/build-linux.sh
```

Or open `chess.pro` in Qt Creator and build Release.

## Package / distribute

```bash
./scripts/package-linux.sh          # → dist/Bu-Ali-Chess-linux.zip
```

Windows (from Qt Command Prompt):

```bat
packaging\windows\build-windows.bat
packaging\windows\package-windows.bat
```

## Legacy release folders

Older packages under `Bu-Ali Chess (linux)` and `Bu-Ali Chess(windows)` are incomplete
(missing bundled Qt libs / `.exe`). Prefer regenerating with the scripts above.

## Project layout

| Path | Role |
|------|------|
| `main.cpp`, `src/`, `include/` | C++ engine + QML bridge (`connection`) |
| `*.qml`, `functions.js`, `qml.qrc` | UI and assets |
| `chess.pro` / `CMakeLists.txt` | Build files |
| `scripts/` | Linux build & package |
| `packaging/` | Desktop entry + Windows helpers |
