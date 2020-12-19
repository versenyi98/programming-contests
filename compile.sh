#!bin/bash

# Add the following line to ~/.bashrc:
# source /path/to/compile.sh

# After this, the terminal should recognize the compile command

function compile() {
    g++ "$PWD/main.cpp" -o "$PWD/main"
}