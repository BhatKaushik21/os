#!/bin/sh
echo Enter a number
read n
r=0
m=$n
k=10;
while [ $n -gt 0 ]
do
	r=$(( $n % 10 ))
	re=$((( $rev * 10 ))
	rev=$(( $re + $r ))
	n=` expr $n / 10 `
done
if [ $rev -eq $m ]
then
	echo "Palindrome"
else
	echo Not palindrome
fi