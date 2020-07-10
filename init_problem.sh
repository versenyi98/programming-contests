#!/bin/bash

FOLDER_NAME=$1
PROBLEM_LINK={$2:-""}

mkdir "$FOLDER_NAME"
cd "$FOLDER_NAME"
touch in main.cpp README.md
echo $2 > README.md
printf "#include <bits/stdc++.h>\n\nusing namespace std;\n\nint main() {\n\n}\n" > main.cpp

code . *