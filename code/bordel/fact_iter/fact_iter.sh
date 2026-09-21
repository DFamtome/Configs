#!/bin/sh


if [ $# -ne 1 ]; then
	exit 1
fi

res=1

for i in $(seq 2 $1) ; do
	res=$(($res * i))
done

echo $res
