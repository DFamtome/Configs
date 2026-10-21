#!/bin/sh

if [ ! -f 'libmalloc.so' ]; then
	make library -C .
fi

LD_PRELOAD=./libmalloc.so cat 'tests/test.sh' > /dev/null

if [ 0 -ne $? ]; then
	echo KO
else
	echo OK
fi

