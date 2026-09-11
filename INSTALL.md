# راهنمای نصب و ساخت — Bu-Ali Chess (Qt 6)

بله، مهاجرت به **Qt 6 ممکن است** و در این شاخه انجام شده است. پروژه با Qt 6.4+ بیلد و اجرا می‌شود؛ در صورت نبودن Qt6، CMake/اسکریپت‌ها به Qt 5.15 برمی‌گردند.

## چه چیزهایی باید نصب کنید؟

### لینوکس — Qt 6 (پیشنهادی)

```bash
sudo apt update
sudo apt install -y \
  build-essential cmake qmake6 \
  qt6-base-dev qt6-declarative-dev qt6-multimedia-dev \
  qml6-module-qtquick \
  qml6-module-qtquick-controls \
  qml6-module-qtquick-layouts \
  qml6-module-qtquick-window \
  qml6-module-qtquick-templates \
  qml6-module-qtmultimedia \
  qml6-module-qtqml \
  qml6-module-qtqml-models \
  qml6-module-qtqml-workerscript \
  gstreamer1.0-plugins-base \
  gstreamer1.0-plugins-good \
  gstreamer1.0-libav
```

### لینوکس — Qt 5.15 (اختیاری / سازگاری)

```bash
sudo apt install -y build-essential cmake qt5-qmake qtbase5-dev \
  qtdeclarative5-dev qtquickcontrols2-5-dev qtmultimedia5-dev \
  libqt5multimedia5-plugins qml-module-qtquick-controls2 \
  qml-module-qtmultimedia qml-module-qtquick-layouts \
  qml-module-qtgraphicaleffects
```

### ویندوز

1. [Qt Online Installer](https://www.qt.io/download-qt-installer)
2. انتخاب **Qt 6.5+** یا **6.4+** (MinGW یا MSVC)
3. ماژول‌ها: Qt Quick, Quick Controls, Multimedia
4. Qt Creator

### macOS

```bash
brew install qt cmake
export PATH="$(brew --prefix qt)/bin:$PATH"
```

## تغییرات مهم Qt5 → Qt6

| موضوع | کار انجام‌شده |
|--------|----------------|
| `Audio {}` | موسیقی با `MediaPlayer` + `AudioOutput`؛ افکت‌ها با `SoundEffect` |
| importهای نسخه‌دار | import بدون نسخه (`import QtQuick`) |
| `AA_EnableHighDpiScaling` | فقط برای Qt5 نگه داشته شد |
| Controls.Styles (Controls 1) | حذف شد (در Qt6 وجود ندارد) |

## ساخت

```bash
chmod +x scripts/*.sh
./scripts/build-linux.sh
```

اسکریپت اول `qmake6` را امتحان می‌کند. خروجی: `build-release/chess`

دستی:

```bash
mkdir -p build-qt6 && cd build-qt6
qmake6 ../chess.pro CONFIG+=release
make -j$(nproc)
```

یا CMake (اول Qt6 را پیدا می‌کند):

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release -j
```

## فایل نصب / پکیج

```bash
./scripts/package-linux.sh
```

→ `dist/Bu-Ali-Chess-linux.zip`

ویندوز (از Qt 6 Command Prompt):

```bat
packaging\windows\build-windows.bat
packaging\windows\package-windows.bat
```

## نکته

پوشه‌های قدیمی `Bu-Ali Chess (linux)` / `Bu-Ali Chess(windows)` مربوط به Qt5 قدیمی‌اند؛ پکیج جدید را با اسکریپت‌ها بسازید.
