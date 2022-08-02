echo Enter three nos
read a
read b
read c
echo Largest is
if [ $a -gt $b ]
then 
	if [ $a -gt $c ]
	then
		echo $a 
	else
		echo $c 
	fi
else if [ $b -gt $a ]
then 
	if [ $b -gt $c ]
	then
		echo $b
	else
		echo $c
	fi
fi