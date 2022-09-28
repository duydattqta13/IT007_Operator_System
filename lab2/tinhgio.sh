#!/bin/sh
hour=$1
minute=$2
timeforwork=$3

result=$4

>$4

if [ $1 -ge 24 ]; then
	echo "Gio khong hop le" > $4
	exit 1
fi

if [ $2 -ge 60 ]; then
	echo "Phut khong hop le" > $4
	exit 1
fi

if [ $3 -gt 480 ]; then
	echo "Thoi gian lam viec khong hop le" > $4
	exit 1
fi

minute=$(($minute+$timeforwork))
minute_1=$(($minute/60))

if [ $minute -ge 60 ]; then
	minute=$((minute%60))
	hour=$(($hour+$minute_1))
	if [ $hour -lt 24 ]; then
		echo "$hour $minute" > $4
		exit 0
	else
		hour=$(($hour%24))
		echo "$hour $minute" > $4
		exit 0
	fi
fi
exit 0

