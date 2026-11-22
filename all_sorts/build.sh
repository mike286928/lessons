#!/usr/bin/env sh
set -e
cd "$(dirname "$0")"

BUILD_TYPE=Ninja
BUILD_SUFFIX=ninja
BUILD_FOLDER=build_$BUILD_SUFFIX
SOURCE_FOLDER=src

mkdir -p "$BUILD_FOLDER"
cd "$BUILD_FOLDER"

cmake -G "$BUILD_TYPE" -DCMAKE_BUILD_TYPE=Release "../$SOURCE_FOLDER"
cmake --build .
