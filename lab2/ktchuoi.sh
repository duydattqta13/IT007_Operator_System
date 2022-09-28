#!/bin/sh

> $3

if [ ! -d $2 ]; then
	echo "Thu muc $2 khong ton tai" > $3
	exit 1
fi

count=0

for file in $2/*; do
	if grep -Fxq $1 $file; then
		count=$(($count+1))
fi
done

if [ $count -eq 0 ]; then
	echo "Trong thu muc $2 khong co tap tin nao chua chuoi $1" > $3
else
	echo "Trong thu muc $2 co $count tap tin chua chuoi $1" > $3
fi
exit 0
