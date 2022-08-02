declare -A a
declare -A b
declare -A c
echo Enter the elements of matrix A
for((i=0;i<2;i++))
do
	for((j=0;j<2;j++))
	do
		read a[$i,$j]
	done
done
echo Enter the elements of matrix B
for((i=0;i<2;i++))
do
	for((j=0;j<2;j++))
	do
		read b[$i,$j]
	done
done
echo Printing the elements of matrix A
for((i=0;i<2;i++))
do
	for((j=0;j<2;j++))
	do
		echo -ne "${a[$i,$j]} "
	done
	echo
done
echo Printing the elements of matrix B
for((i=0;i<2;i++))
do
	for((j=0;j<2;j++))
	do
		echo -ne "${b[$i,$j]} "
	done
	echo
done
echo Printing the elements of matrix C i.e., after addtion of Matrix A and Matrix B
for((i=0;i<2;i++))
do
	for((j=0;j<2;j++))
	do
		echo -ne "$((${a[$i,$j]}+${b[$i,$j]})) "
	done
	echo
done