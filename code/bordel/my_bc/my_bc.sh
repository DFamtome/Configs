#!/bin/sh

if [ $# -eq 0 ]; then
	while [ 1 ];  do
		read 

		if [ -d $EOF $REPLY ]; then 
			exit
		fi

		echo $(("$REPLY"))

	done
fi


echo $(("$REPLY"))
