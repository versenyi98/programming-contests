#!/bin/bash

FOLDER_NAME=$1

mkdir "$FOLDER_NAME"
cd "$FOLDER_NAME"
touch in main.cpp README.md
cd ..

code "$FOLDER_NAME"