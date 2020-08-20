#!/bin/bash

PWD=$(basename "$(pwd)")
LAST_DIR=$(pwd)

cd ../../
./generate_readme.sh > README.md
cd "$LAST_DIR"
git add .
git commit -a -m "Add $PWD"
git push