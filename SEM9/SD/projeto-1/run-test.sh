#!/usr/bin/env sh

if [ -z $2 ]; then
	echo "Usage: $0 <NUMBER OF CLIENTS> <NUMBER OF TESTS>"
	exit -1
fi

 > result.out

N=$2
while [ $N -ne 0 ]; do
	echo "===== Test #$(( $2 - $N + 1 )) =====" >> result.out
	M=$1
	while [ $M -ne 0 ]; do
		./launch-client.sh $(( $1 - $M + 1 )) &
		M=$(( $M - 1 ))
	done
	./server.out $1 >> result.out
	echo "" >> result.out
	N=$(( $N - 1 ))
done