#!/bin/sh

ext=txt
if [ $# -ne 0 ]; then
	ext=$1
fi

files="$(echo *.$ext)"

if [ "$files" = "*.$ext" ];then
	exit 1
fi

for elt in $files; do
	if [ -f "$elt" ]; then
		rm $elt
	fi
done
