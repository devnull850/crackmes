#!/bin/bash

if [ ! -f crack ];
then
	gcc -Wall crack.c -o crack
fi

for i in {0..59}
do
	ARG=$(./crack)
	./license_checker_3 $ARG
	sleep 1
done
