# راهنمای نصب — Bu-Ali Chess

اگر `apt` خطای زیر را داد:

```text
E: Unable to locate package qmake6
E: Package 'qt6-base-dev' has no installation candidate
```

یعنی روی سیستم شما **پکیج Qt 6 در مخازن نیست** (اوبونتو قدیمی‌تر از 22.04، یا مخزن `universe` خاموش است).

---

## راه سریع (پیشنهادی): نصب Qt 5

روی اکثر سیستم‌های لینوکس این کار می‌کند:

```bash
sudo apt update
sudo apt install -y \
  build-essential \
  qt5-qmake \
  qtbase5-dev \
  qtdeclarative5-dev \
  qtquickcontrols2-5-dev \
  qtmultimedia5-dev \
  libqt5multimedia5-plugins \
  qml-module-qtquick-controls2 \
  qml-module-qtmultimedia \
  qml-module-qtquick-layouts \
  qml-module-qtgraphicaleffects \
  gstreamer1.0-plugins-good \
  gstreamer1.0-libav
```

بعد:

```bash
git clone -b cursor/complete-install-packaging-f845 https://github.com/alizeinodin/Chess-Game.git
cd Chess-Game
chmod +x scripts/*.sh
./scripts/build-linux.sh
./build-release/chess
```

---

## اگر اوبونتو 22.04 یا 24.04 دارید و می‌خواهید Qt 6

```bash
sudo add-apt-repository universe
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
  qml6-module-qtqml-workerscript
```

اول نسخه سیستم را چک کنید:

```bash
cat /etc/os-release
```

- Ubuntu **20.04 یا قدیمی‌تر** → از **Qt 5** استفاده کنید (بخش بالا)
- Ubuntu **22.04 / 24.04** → با `universe` باید Qt 6 پیدا شود

---

## ویندوز

از [نصب‌کننده رسمی Qt](https://www.qt.io/download-qt-installer) نسخه **5.15** یا **6.x** را نصب کنید (ماژول‌ها: Quick, Quick Controls, Multimedia)، بعد:

```bat
packaging\windows\build-windows.bat
```

---

## تشخیص سریع

```bash
cat /etc/os-release
apt-cache search qt5-qmake | head
apt-cache search qmake6 | head
```
