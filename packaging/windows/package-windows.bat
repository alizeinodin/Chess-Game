@echo off
REM Bundle Qt DLLs next to chess.exe using windeployqt
setlocal

set ROOT=%~dp0..\..
set BUILD=%ROOT%\build-windows
set DIST=%ROOT%\dist\Bu-Ali-Chess-windows

if not exist "%BUILD%\release\chess.exe" if not exist "%BUILD%\chess.exe" (
  echo Build the game first: packaging\windows\build-windows.bat
  exit /b 1
)

where windeployqt >nul 2>&1
if errorlevel 1 (
  echo windeployqt not found. Use the Qt Command Prompt.
  exit /b 1
)

if exist "%DIST%" rmdir /s /q "%DIST%"
mkdir "%DIST%"

if exist "%BUILD%\release\chess.exe" (
  copy /Y "%BUILD%\release\chess.exe" "%DIST%\chess.exe"
) else (
  copy /Y "%BUILD%\chess.exe" "%DIST%\chess.exe"
)

windeployqt --qmldir "%ROOT%" --release --compiler-runtime "%DIST%\chess.exe"
if errorlevel 1 exit /b 1

echo.
echo Portable Windows folder ready:
echo   %DIST%
echo Zip that folder to distribute the game.
endlocal
