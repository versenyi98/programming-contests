#!/bin/sh

printf "## Kattis problems   \n"
printf "| Link to description | Link to solution |   \n"
printf "|:---|:---:|   \n"
cd Kattis
for d in * ; do
    cd "$d"
    printf "| [$d]("
    res=$(cat README.md | grep kattis | head -n 1)
    dir=$(echo "$d" | sed 's,\ ,%20,g')
    echo "$res) | [Solution](https://github.com/versenyi98/programming-contests/tree/master/Kattis/$dir)|   "
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
    res=$(cat README.md | grep onlinejudge | head -n 1)
    dir=$(echo "$d" | sed 's,\ ,%20,g')
    echo "$res) | [Solution](https://github.com/versenyi98/programming-contests/tree/master/UVa%20Online%20Judge/$dir)|   "
    cd ..
done