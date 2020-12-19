#!bin/bash

# Add the following line to ~/.bashrc:
# source /path/to/setup.sh

# After this, the terminal should recognize the following commands

function compile() {
    g++ "$PWD/main.cpp" -o "$PWD/main"
}

function generate_readme() {
    printf "## Kattis problems   \n"
    printf "| ID | Link to description | Link to solution |   \n"
    printf "|:---|:---|:---:|   \n"
    cd Kattis
    for d in * ; do
        cd "$d"
        description=$(cat README.md | grep kattis | head -n 1)
        modified_dir_name=$(echo "$d" | sed 's,\ ,%20,g')
        id=$(echo $description| cut -d'/' -f 5)

        printf "| $id | [$d]("

        echo "$description) | [Solution](https://github.com/versenyi98/programming-contests/tree/master/Kattis/$modified_dir_name)|   "
        cd ..
    done
    cd ..

    printf "## UVa Online Judge problems   \n"
    printf "| Link to description | Link to solution |   \n"
    printf "|:---|:---:|   \n"

    cd "UVa Online Judge"
    for d in * ; do
        cd "$d"
        printf "| [$d]("
        description=$(cat README.md | grep onlinejudge | head -n 1)
        modified_dir_name=$(echo "$d" | sed 's,\ ,%20,g')
        echo "$description) | [Solution](https://github.com/versenyi98/programming-contests/tree/master/UVa%20Online%20Judge/$modified_dir_name)|   "
        cd ..
    done
    cd ..
}

function commit_changes() {
    LAST_DIR=$PWD

    cd ../../
    generate_readme > README.md
    cd "$LAST_DIR"

    git add .
    git commit -a -m "Add $(basename "$(pwd)")"
}

function init_problem() {
    FOLDER_NAME=$1
    PROBLEM_LINK=$2

    mkdir "$PWD/$FOLDER_NAME"
    cd "$FOLDER_NAME"

    touch in main.cpp README.md

    echo $PROBLEM_LINK > README.md

    printf "#include <bits/stdc++.h>
#define endl \"\\\n\"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}" > main.cpp
}