#!/bin/sh

# Files .c for Makefile

if [ "$(echo *.c)" = '*.c' ]; then
	if [ "$(echo ./*/*.c)" = './*/*.c' ]; then
		echo No such .c file in the current directory
		exit 1;
	else
		echo 'SRC    =' ./*/*.c > Makefile
	fi
else
	if [ "$(echo ./*/*.c)" = './*/*.c' ]; then
		echo 'SRC    =' *.c > Makefile
	else
		echo 'SRC    =' *.c ./*/*.c > Makefile
	fi
fi

cat ~/afs/.scripts/data/Makefile >> Makefile

if [ "$(echo *.h)" = '*.h' ]; then
	if [ "$(echo ./*/*.h)" = './*/*.h' ]; then
		echo No such .h file in the.hurrent directory
	else
		for f in "$(echo ./*/*.h)"; do 
			echo '#include "'$f'"' >> tests.c
		done
		cat tests.c > main.c
	fi
else
	if [ "$(echo ./*/*.h)" = './*/*.h' ]; then
		for f in "$(echo *.h)"; do 
			echo '#include "'$f'"' >> tests.c
		done

		cat tests.c > main.c
	else
		for f in "$(echo *.h ./*/*.h)"; do 
			echo '#include "'$f'"' >> tests.c
		done

		cat tests.c > main.c
	fi
fi

cat ~/afs/.scripts/data/main.c >> main.c
cat ~/afs/.scripts/data/tests.c >> tests.c

