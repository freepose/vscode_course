#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

C_FILES="src/snake.c src/ui.c src/auto.c"
OUT_DIR="macos"
OUT="$OUT_DIR/snake"

UNAME_S=$(uname -s)

echo "============================================="
echo "[Snake Game - macOS / Linux Build]"
echo "============================================="
echo ""

# Create output dir
mkdir -p "$OUT_DIR"

check_deps() {
    if ! command -v gcc >/dev/null 2>&1 && ! command -v clang >/dev/null 2>&1; then
        echo "[ERROR] gcc or clang not found!"
        echo "Install via:"
        echo "  macOS:    brew install gcc"
        echo "  Ubuntu:   sudo apt install build-essential"
        echo "  Arch:     sudo pacman -S gcc"
        exit 1
    fi
    if [ "$UNAME_S" = "Darwin" ]; then
        if ! pkg-config --exists raylib 2>/dev/null; then
            local found=0
            for libdir in /usr/local/lib /opt/homebrew/lib; do
                if [ -f "$libdir/libraylib.dylib" ]; then
                    found=1
                    break
                fi
            done
            if [ "$found" = "0" ]; then
                echo "[ERROR] raylib not found!"
                echo "  brew install raylib"
                exit 1
            fi
        fi
    elif [ "$UNAME_S" = "Linux" ]; then
        if ! pkg-config --exists raylib 2>/dev/null && [ ! -f /usr/lib/libraylib.so ]; then
            echo "[ERROR] raylib not found!"
            echo "  Ubuntu/Debian: sudo apt install libraylib-dev"
            echo "  Arch:           sudo pacman -S raylib"
            exit 1
        fi
    fi
}

check_deps

CC=$(command -v gcc 2>/dev/null || command -v clang)

if [ "$UNAME_S" = "Darwin" ]; then
    echo "[macOS] Building..."
    if pkg-config --exists raylib 2>/dev/null; then
        CFLAGS=$(pkg-config --cflags raylib)
        LDFLAGS=$(pkg-config --libs raylib)
    else
        for libdir in /usr/local/lib /opt/homebrew/lib; do
            if [ -f "$libdir/libraylib.dylib" ]; then
                CFLAGS="-I/usr/local/include -I/opt/homebrew/include"
                LDFLAGS="-L$libdir -lraylib"
                break
            fi
        done
    fi
    $CC -o "$OUT" $C_FILES $CFLAGS $LDFLAGS \
        -framework cocoa -framework opengl -framework iokit -framework corevideo -lm \
        -Wall -Wextra
    echo "Done: $OUT"

elif [ "$UNAME_S" = "Linux" ]; then
    echo "[Linux] Building..."
    if pkg-config --exists raylib 2>/dev/null; then
        CFLAGS=$(pkg-config --cflags raylib)
        LDFLAGS=$(pkg-config --libs raylib)
    else
        CFLAGS="-I/usr/include"
        LDFLAGS="-L/usr/lib -lraylib -lGL -lm -lpthread -ldl -lrt"
    fi
    $CC -o "$OUT" $C_FILES $CFLAGS $LDFLAGS -Wall -Wextra
    echo "Done: $OUT"

else
    echo "[Windows (WSL)] Building..."
    $CC -o "$OUT.exe" $C_FILES \
        -Isrc -lraylib -lgdi32 -lwinmm -Wall -Wextra
    echo "Done: $OUT.exe"
fi

echo ""
echo "============================================="
echo "BUILD SUCCESS: $OUT"
echo "============================================="
echo ""
echo "To run:"
echo "  cd $OUT_DIR"
echo "  ./snake"
if [ "$UNAME_S" = "Darwin" ]; then
    echo ""
    echo "Note: Apple Silicon Mac, run with:"
    echo "  DYLD_LIBRARY_PATH=/opt/homebrew/lib ./snake"
fi
echo ""
echo "Controls:"
echo "  Arrow Keys / WASD  Move snake"
echo "  SPACE / P         Pause / Resume"
echo "  A                 Toggle Auto-play"
echo "  R                 Restart"
echo "  ESC               Quit"
