#!bin/bash
set -eu

DIRECTORY=$1

for dir in $(ls $DIRECTORY)
do
    if [[ -d $dir ]]
    then
        cd $dir
        touch README.md
        echo -e "$dir" ' \t ' "$(cat README.md)"
        cd ..
    fi
done