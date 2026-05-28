@echo off
gcc -o snake.exe snake.c
if %errorlevel% == 0 (
    echo Build success: snake.exe
) else (
    echo Build failed.
)
pause
