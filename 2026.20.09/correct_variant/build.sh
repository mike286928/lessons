#!/bin/sh
set -eu

# Сборка работает независимо от текущей папки терминала.
cd "$(dirname "$0")"

# На macOS используем Command Line Tools, если компилятор не задан через CXX.
set --
if [ -n "${CXX:-}" ]; then
    compiler="$CXX"
elif [ "$(uname -s)" = "Darwin" ] && [ -x /Library/Developer/CommandLineTools/usr/bin/clang++ ]; then
    compiler=/Library/Developer/CommandLineTools/usr/bin/clang++
    set -- -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk
else
    compiler=c++
fi

"$compiler" "$@" -std=c++17 -Wall -Wextra main.cpp io.cpp sortings.cpp -o example
printf 'Сборка завершена: %s/example\n' "$PWD"
printf 'Запуск: "%s/example"\n' "$PWD"
