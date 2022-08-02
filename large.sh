echo Enter an array
read -a A

n=${#A[*]}
large=${A[0]}
for((i=1;i<$n;i++))
do
	if [ ${A[$i]} -gt $large ] ;then
		large=${A[$i]}
	fi
done
echo Largest is $large