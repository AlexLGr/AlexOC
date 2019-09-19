#!/bin/bash

input=$1;
while(1>0)
do
	if ln "$input" "$input.protected"
	then
		ll="$(cat "$input" | tail -1)"
		nl=$((ll+1))
		echo "$next_line" >> "$input"
		rm "$input.protected"
	fi
done
