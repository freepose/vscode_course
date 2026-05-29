@echo off
setlocal enabledelayedexpansion

set "SCRIPT_DIR=%~dp0"
cd /d "%SCRIPT_DIR%"

:: Output to win/ folder
set "OUT_DIR=%SCRIPT_DIR%win"
set "OUT=%OUT_DIR%\snake.exe"

set C_FILES=src\snake.c src\ui.c src\auto.c

echo =============================================
echo [Snake Game - Windows Build]
echo =============================================
echo.

:: Create output dir
if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"

:: Check gcc
where gcc >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] gcc not found!
    echo Please ensure MinGW gcc is in PATH or at C:\mingw\bin
    exit /b 1
)

:: Check raylib
where raylib >nul 2>&1
if %errorlevel% neq 0 (
    if not exist "C:\mingw\lib\raylibdll.a" (
        echo [WARNING] raylib not found in PATH!
        echo Expected at C:\mingw\lib\raylibdll.a
    )
)

:: Build
echo [Building] %C_FILES% ...
gcc -o "%OUT%" %C_FILES% -Isrc -IC:\mingw\include -LC:\mingw\lib ^
    -lraylibdll -lgdi32 -lwinmm -lcomdlg32 -lpthread -Wall -Wextra -O2

if %errorlevel% neq 0 (
    echo.
    echo [BUILD FAILED]
    exit /b 1
)

:: Copy DLL
if exist "C:\mingw\lib\raylib.dll" (
    copy /y "C:\mingw\lib\raylib.dll" "%OUT_DIR%" >nul
    echo [Copied raylib.dll to win\]
)

echo.
echo =============================================
echo [BUILD SUCCESS] %OUT%
echo =============================================
echo.
echo To run:
echo   cd %OUT_DIR%
echo   snake.exe
echo.
echo Controls:
echo   Arrow Keys / WASD  Move snake
echo   SPACE / P          Pause / Resume
echo   A                  Toggle Auto-play
echo   R                  Restart
echo   ESC                Quit
echo.
