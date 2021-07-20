#!/usr/bin/env sh

if [ -z "$1" ]; then
    echo "Usage: $0 <NUMBER OF CLIENTS>"
    exit -1
fi

N=$1
tmux new-session -d "./server.out $N && read -rsp $'Press any key to continue...\n' -n1 key"
while [ "$N" -ne 0 ]; do
    if [ "$N" -eq "$1" ]; then
        tmux split-window -h "./client.out $N && read -rsp $'Press any key to continue...\n' -n1 key"
        tmux resize-pane -t 0 -x 5
    elif [ "$1" -eq 16 -a "$N" -le 8 ]; then
        I=$((( 9 - $N ) * 2 - 1))
        tmux split-window -t $I -h "./client.out $N && read -rsp $'Press any key to continue...\n' -n1 key"
        tmux resize-pane -t $I -x 5
    else
        I=$(($1 - $N))
        tmux split-window -t $I -v "./client.out $N && read -rsp $'Press any key to continue...\n' -n1 key"
        tmux resize-pane -t $I -y 1
    fi
    N=$(($N - 1))
done
tmux attach-session
