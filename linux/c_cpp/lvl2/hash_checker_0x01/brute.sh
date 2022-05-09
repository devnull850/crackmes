#!/bin/bash

for a in {0..9}
do
for b in {0..9}
do
for c in {0..9}
do
for d in {0..9}
do
for e in {0..9}
do
for f in {0..9}
do
	RESULT=`./crackme "$a$b$c$d$e$f"`

	if [ "$RESULT" = "Key is valid" ];
	then
		echo "$a$b$c$d$e$f"
	fi
done
done
done
done
done
done
