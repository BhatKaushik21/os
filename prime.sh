echo Enter the range
read a 
read b
flag=1
for (( i=$a ; i <= $b ; i++ ))
do
	flag=1
	for (( j=2 ; j <= $(( $i / 2 )) ; j++ ))
	do
		if [[ $i == 2 || $i == 3 ]]
		then
			flag=0
			break
		fi
		if [ $(( $i % $j )) == 0 ]
		then
			flag=1
			break
		fi		
	done
	if [ $flag == 0 ]
	then 
		echo "$i "
	fi
done