#!/bin/bash

for i in {0..59}
do
	rm args
	./crack
	ARGS=$(cat args)
	./de_mucholoko $ARGS
	sleep 1
done
