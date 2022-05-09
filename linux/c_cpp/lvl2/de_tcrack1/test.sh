#!/bin/bash

rm arg

for i in {0..59}
do
	./crack
	ARG=$(cat arg)

	./de_tcrack1 "$ARG"

	echo ""

	sleep 1
done
