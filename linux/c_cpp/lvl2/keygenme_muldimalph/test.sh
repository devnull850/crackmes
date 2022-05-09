#!/bin/bash

for i in {0..59}
do
	rm serial
	./crack
	ARG=$(cat serial)
	MSG=$(./muldimalph $ARG)

	if [ "$MSG" = "Serial is valid!" ];
	then
		echo "$ARG pass"
	else
		echo "$ARG fail"
	fi

	sleep 1
done
