#!/bin/sh

TEXT=$(amixer sget Master)

PERCENT=$(echo $TEXT | awk -F "[][]" '/%/ {print $2}' | head -n1)

echo $PERCENT
