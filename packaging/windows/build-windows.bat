@echo off
REM Build Bu-Ali Chess on Windows (requires Qt 5.12+ with MinGW or MSVC)
setlocal

where qmake >nul 2>&1
if errorlevel 1 (
  echo qmake not found. Open "Qt 5.x Command Prompt" or add Qt bin to PATH.
  exit /b 1
)

if not exist build-windows mkdir build-windows
cd build-windows
qmake ..\chess.pro -spec win32-g++ "CONFIG+=release"
mingw32-make -j%NUMBER_OF_PROCESSORS%
if errorlevel 1 exit /b 1

echo.
echo Binary: %CD%\release\chess.exe  (or .\chess.exe depending on kit)
echo Next: run packaging\windows\package-windows.bat
endlocal
