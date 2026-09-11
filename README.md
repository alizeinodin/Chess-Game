# Bu-Ali Chess

Chess game for the advanced programming course at Bu-Ali Sina University.

C++ backend + QML frontend. Targets **Qt 6** (falls back to Qt 5.15).

## Features

- OOP chess engine (moves, check/mate, castling, en passant, promotion, undo)
- Save/load via `.acd` files
- Qt Quick UI (Material) with sound

## Requirements

See **[INSTALL.md](INSTALL.md)** for full Persian + English steps.

### Ubuntu / Debian (Qt 6)

```bash
sudo apt install -y build-essential cmake qmake6 \
  qt6-base-dev qt6-declarative-dev qt6-multimedia-dev \
  qml6-module-qtquick qml6-module-qtquick-controls \
  qml6-module-qtquick-layouts qml6-module-qtquick-window \
  qml6-module-qtquick-templates qml6-module-qtmultimedia \
  qml6-module-qtqml qml6-module-qtqml-models \
  qml6-module-qtqml-workerscript \
  gstreamer1.0-plugins-good gstreamer1.0-libav
```

## Build & package

```bash
chmod +x scripts/*.sh
./scripts/build-linux.sh      # prefers qmake6
./scripts/package-linux.sh    # → dist/Bu-Ali-Chess-linux.zip
```

Or open `chess.pro` in Qt Creator with a **Qt 6** kit.

Windows: `packaging\windows\build-windows.bat` then `package-windows.bat` (Qt 6 kit).

## Project layout

| Path | Role |
|------|------|
| `main.cpp`, `src/`, `include/` | Engine + QML bridge |
| `*.qml`, `qml.qrc` | UI / assets |
| `chess.pro` / `CMakeLists.txt` | Qt6 (preferred) / Qt5 fallback |
| `scripts/` | Linux build & package |
