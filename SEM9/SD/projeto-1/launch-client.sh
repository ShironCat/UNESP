#!/usr/bin/env sh

if [ -z "$1" ]; then
	echo "Usage: $0 <CLIENT ID>"
	exit -1
fi

sleep 10
./client.out $1 > /dev/null