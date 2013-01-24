#!/bin/bash

for i in $(seq 0 100)
do
	let t=i%3
	let c=i%5
	if [ $c -eq 0 ]
	then
		printf "PING "
	fi
	if [ $t -eq 0 ]
	then
		printf "PONG "
	fi
	
	echo ""
done
