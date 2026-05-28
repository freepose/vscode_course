#!/usr/bin/env bash
# ─────────────────────────────────────────────────────────────
#  build_snake_win.sh
#
#  在 macOS / Linux 上用 MinGW-w64 交叉编译 snake_win.c，
#  产物为 Windows 可执行文件 snake_win.exe。
#
#  依赖（任选一种安装方式）：
#    macOS:  brew install mingw-w64
#    Debian/Ubuntu:  sudo apt-get install mingw-w64
#    Arch:           sudo pacman -S mingw-w64-gcc
#    Fedora:         sudo dnf install mingw64-gcc
#
#  用法：
#    ./build_snake_win.sh              # 普通发布构建
#    ./build_snake_win.sh debug        # 带调试符号 + 控制台窗口
#    ./build_snake_win.sh clean        # 删除产物
#    ./build_snake_win.sh run          # 构建后用 wine 运行（需安装 wine）
# ─────────────────────────────────────────────────────────────

set -euo pipefail

cd "$(dirname "$0")"

SRC="snake_win.c"
OUT="snake_win.exe"

# 使用系统自带的 gcc（macOS 上通常是 clang 的 gcc 别名，Linux 上是真 gcc）
# 若系统未提供 gcc，则回退到 cc
if command -v gcc >/dev/null 2>&1; then
    CC="gcc"
elif command -v cc >/dev/null 2>&1; then
    CC="cc"
else
    echo "✗ 未找到系统 gcc / cc 编译器。" >&2
    exit 1
fi

MODE="${1:-release}"

case "$MODE" in
    clean)
        rm -f "$OUT"
        echo "✓ 已清理 $OUT"
        exit 0
        ;;
    debug)
        CFLAGS="-std=c99 -Wall -Wextra -O0 -g"
        # debug 模式保留控制台窗口（去掉 -mwindows），方便看 printf/断言
        LDFLAGS="-lgdi32"
        ;;
    release|run)
        CFLAGS="-std=c99 -Wall -Wextra -O2 -s"
        LDFLAGS="-lgdi32 -mwindows"
        ;;
    *)
        echo "未知模式: $MODE  (可用: release | debug | clean | run)" >&2
        exit 2
        ;;
esac

if [[ ! -f "$SRC" ]]; then
    echo "✗ 找不到源文件 $SRC" >&2
    exit 1
fi

echo "→ 使用编译器: $CC"
echo "→ 模式:       $MODE"
echo "→ 编译命令:   $CC $CFLAGS -o $OUT $SRC $LDFLAGS"

$CC $CFLAGS -o "$OUT" "$SRC" $LDFLAGS

echo "✓ 构建成功: $OUT  ($(du -h "$OUT" | cut -f1))"

if [[ "$MODE" == "run" ]]; then
    if command -v wine >/dev/null 2>&1; then
        echo "→ 用 wine 运行..."
        exec wine "$OUT"
    else
        echo "⚠ 未安装 wine，跳过运行。可执行文件已生成: $OUT" >&2
    fi
fi
