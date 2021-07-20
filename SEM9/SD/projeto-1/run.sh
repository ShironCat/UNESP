#!/usr/bin/env sh

 > result.out

port=8080

for i in 2 4 8 16 32; do
	echo "===== Run #${i} =====" >> result.out
	port=$(($port + $i))
	j=$i
	while [ $j -ne 0 ]; do
		./launch-client.sh $j $port &
		j=$(( $j - 1 ))
	done
	./server.out $i $port >> result.out
	echo "" >> result.out
done
