@echo off
REM Build Bu-Ali Chess on Windows (requires Qt 5.12+ with MinGW or MSVC)
setlocal

where qmake >nul 2>&1
if errorlevel 1 (
  echo qmake not found. Open a Qt 6 Command Prompt or add Qt bin to PATH.
  exit /b 1
)

qmake -v
echo.
echo Use a Qt 6 kit. Qt 5.15 may still work as fallback.
echo.

if not exist build-windows mkdir build-windows
cd build-windows
qmake ..\chess.pro "CONFIG+=release"
mingw32-make -j%NUMBER_OF_PROCESSORS%
if errorlevel 1 (
  nmake
  if errorlevel 1 exit /b 1
)

echo.
echo Binary built under build-windows\
echo Next: run packaging\windows\package-windows.bat
endlocal
