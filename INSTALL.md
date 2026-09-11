# راهنمای نصب و ساخت — Bu-Ali Chess

بله، تکمیل و آماده‌سازی فایل نصب **ممکن است**. این پروژه یک بازی شطرنج با **Qt 5 + QML** است (بک‌اند C++، فرانت‌اند QML).

## وضعیت فعلی پروژه

| بخش | وضعیت |
|-----|--------|
| منطق بازی (C++/QML) | کامل (en passant، قلعه، ارتقای پیاده، کیش/مات، ذخیره فایل `.acd`) |
| `chess.pro` | قابل بیلد با qmake |
| `CMakeLists.txt` | به‌روز شده برای Qt5 |
| پکیج لینوکس `Bu-Ali Chess (linux)` | قدیمی/ناقص — از `scripts/package-linux.sh` استفاده کنید |
| پکیج ویندوز `Bu-Ali Chess(windows)` | ناقص — `.exe` و DLLها در ریپو نیستند (`.gitignore`) |
| اسکریپت‌های بیلد/پکیج | آماده (`scripts/`, `packaging/`) |
| `delplayer1.cpp` | اسکچ استفاده‌نشده؛ در بیلد اصلی نیست |

## چه چیزهایی باید نصب کنید؟

### لینوکس (Ubuntu / Debian)

**برای توسعه و بیلد:**

```bash
sudo apt update
sudo apt install -y \
  build-essential cmake \
  qt5-qmake qtbase5-dev \
  qtdeclarative5-dev qtquickcontrols2-5-dev \
  qtmultimedia5-dev libqt5multimedia5-plugins \
  qml-module-qtquick-controls2 \
  qml-module-qtmultimedia \
  qml-module-qtquick-layouts \
  qml-module-qtgraphicaleffects
```

**برای صدا (GStreamer):**

```bash
sudo apt install -y gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-libav
```

**نسخه پیشنهادی Qt:** 5.12 تا 5.15 (کد با Qt Quick 2.13 و Multimedia 5.9 نوشته شده).

### ویندوز

1. نصب [Qt Online Installer](https://www.qt.io/download-qt-installer)
2. انتخاب **Qt 5.15.x** (یا 5.12+) با یکی از کیت‌ها:
   - MinGW 64-bit **یا** MSVC
3. ماژول‌ها:
   - Qt Quick / QML
   - Qt Quick Controls 2
   - Qt Multimedia
4. نصب **Qt Creator** (پیشنهادی)
5. یک کامپایلر C++ (MinGW همراه Qt، یا Visual Studio Build Tools)

### macOS

```bash
brew install qt@5 cmake
export PATH="$(brew --prefix qt@5)/bin:$PATH"
```

## ساخت پروژه

### لینوکس (سریع)

```bash
chmod +x scripts/*.sh
./scripts/build-linux.sh
```

خروجی: `build-release/chess`

یا دستی با qmake:

```bash
mkdir -p build-release && cd build-release
qmake ../chess.pro CONFIG+=release
make -j$(nproc)
```

یا با CMake:

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release -j
```

### ویندوز

از Qt Command Prompt:

```bat
packaging\windows\build-windows.bat
packaging\windows\package-windows.bat
```

پوشه پرتابل در `dist\Bu-Ali-Chess-windows` ساخته می‌شود.

## آماده‌سازی فایل نصب / پکیج توزیع

### لینوکس

```bash
./scripts/package-linux.sh
```

خروجی:

- `dist/Bu-Ali-Chess-linux/` — پوشه اجرا
- `dist/Bu-Ali-Chess-linux.zip` — فایل توزیع

اگر CQtDeployer/linuxdeployqt نصب باشد، کتابخانه‌های Qt داخل پکیج کپی می‌شوند. در غیر این صورت فقط باینری + اسکریپت اجرا ساخته می‌شود و کاربر باید پکیج‌های runtime را نصب کند (لیست در `INSTALL-DEPS.txt` داخل پکیج).

### ویندوز

بعد از `package-windows.bat`، پوشه `dist\Bu-Ali-Chess-windows` را zip کنید. این همان «فایل نصب/توزیع» پرتابل است (بدون نیاز به Installer جدا).

برای Installer واقعی می‌توانید بعداً از **Inno Setup** یا **NSIS** روی همان پوشه استفاده کنید.

## اجرای نسخه قدیمی داخل ریپو

پوشه لینوکس فعلی کامل نیست. روی سیستمی که Qt5 نصب است ممکن است باینری کار کند:

```bash
cd "Bu-Ali Chess (linux)"
./chess.sh
```

اما برای توزیع به دیگران، حتماً دوباره با `scripts/package-linux.sh` پکیج بسازید.

## خلاصه

| سؤال | جواب |
|------|------|
| آیا ممکن است؟ | بله |
| چه نصب کنم؟ | Qt 5.12–5.15 + ابزار بیلد C++ (+ Multimedia و Quick Controls 2) |
| فایل نصب از کجا؟ | `./scripts/package-linux.sh` یا `packaging\windows\package-windows.bat` |
