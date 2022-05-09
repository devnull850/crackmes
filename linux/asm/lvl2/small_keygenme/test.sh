#!/bin/bash

if [ ! -f crack ];
then
	gcc -Wall crack.c -o crack -Wall
fi

for i in {0..59}
do
	./crack | ./little-crackme
	sleep 1
done
