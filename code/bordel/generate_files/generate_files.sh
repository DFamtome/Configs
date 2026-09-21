#!/bin/sh

if [ $(($#%2)) -ne 0 ]; then
	exit 1
fi

nb_file=1
name_file=default
extension=txt

while [ $# -ne 0 ]; do
	if [ "$1" = '-f' ] || [ "$1" = '--filename' ]; then
		name_file="$2"
	elif [ "$1" = '-e' ] || [ "$1" = '--extension' ]; then
		extension="$2"
			
	elif [ "$1" = '-n' ] || [ "$1" = '--number' ]; then
		nb_file=$2
	else
		exit 2
	fi
	shift 2
done

for n in $(seq $nb_file); do
	touch "./$name_file-$n.$extension"
done
