@echo off
gcc -o snake_win.exe snake_win.c -lgdi32 -mwindows
if %errorlevel% == 0 (
    echo Build success: snake_win.exe
) else (
    echo Build failed.
)
pause
