#!/bin/bash

LAST_DIR=$(pwd)

cd ../../
./generate_readme.sh > README.md
cd "$LAST_DIR"

git add .
git commit -a -m "Add $(basename "$(pwd)")"
git push