#!/bin/sh

text=$(amixer sget Master)

percent=$(echo "$text" | awk -F "[][]" '/%/ {print $2}' | head -n1)
if [[ $(echo "$text" | awk '/%/ { print $6  }' | head -n1) = "[on]" ]]; then 
    echo "$percent"
else
    echo "MUTE"
fi