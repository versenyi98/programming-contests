#!/bin/bash

PWD=$(basename $(pwd))

git add .
git commit -m "Add $PWD"
git push