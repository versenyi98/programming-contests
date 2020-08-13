#!/bin/bash

PWD=$(basename "$(pwd)")
git add .
cd ../../
sh generate_readme.sh > README.md
git commit -m "Add $PWD"
git push