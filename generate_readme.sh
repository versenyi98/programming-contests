#!/bin/sh

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
