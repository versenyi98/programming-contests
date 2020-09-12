#!/bin/bash

FOLDER_NAME=$1
PROBLEM_LINK={$2:-""}

mkdir "$FOLDER_NAME"
cd "$FOLDER_NAME"

touch in main.cpp README.md

echo $2 > README.md

printf "#include <bits/stdc++.h>
#define endl \"\\\n\"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}" > main.cpp

code ../../ ./*