#!/bin/bash

IN_OUT_FOLDER=$1
PROGRAM_PATH=$2

for f in $IN_OUT_FOLDER/*
do

	if [[ $f == *.in ]]
	then
		$PROGRAM_PATH < $f
		echo "============="
	else
		name=$(basename "$f" ".ans")
		echo "$name"
		cat $f
	fi
done
