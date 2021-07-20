#!/usr/bin/env sh

if [ -z "$2" ]; then
	echo "Usage: $0 <CLIENT ID> <PORT>"
	exit -1
fi

sleep 10
./client.out $1 $2 > client-log-$1-$2.out
