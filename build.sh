#! /bin/bash

BUILD_DIR="./build"
GENERATOR="Ninja"

rm -rf "${BUILD_DIR}" 
mkdir "${BUILD_DIR}"&& cd "${BUILD_DIR}" 
cmake -G "${GENERATOR}" ..
ninja
