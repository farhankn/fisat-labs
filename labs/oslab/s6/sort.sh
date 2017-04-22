selectsrt()
{
	echo "ENTER THE LIMIT :"
	read n
	echo "ENTER THE ARRAY ELEMENTS :"
	for((i=0;i<n;i++))
	do
		read a[i]
	done
	echo "THE ARRAY BEFORE SORTING IS :"
	echo ${a[*]}
	for((i=0;i<n-1;i++))
	do
		((min=a[i]))
		((loc=i))
		for((j=i+1;j<n;j++))
		do
			if((a[j]<min))
			then
				((min=a[j]))
				((loc=j))
			fi
		done
		if((loc!=i))
		then
			((temp=a[i]))
			((a[i]=a[loc]))
			((a[loc]=temp))
		fi
		((k=i+1))
		echo "THE ARRAY AFTER PASS " $k "IS "
		echo ${a[*]}
	done
	echo "THE SORTED ARRAY IS :"
	echo ${a[*]}
}
bubble()
{
	echo "ENTER THE LIMIT :"
	read n
	echo "ENTER THE ARRAY ELEMENTS :"
	for((i=0;i<n;i++))
	do
		read a[i]
	done
	echo "THE ARRAY BEFORE SORTING IS :"
	echo ${a[*]}
	for((i=0;i<n-1;i++))
	do
		for((j=0;j<n-i-1;j++))
		do
			if((a[j]>a[j+1]))
			then
				((temp=a[j]))
				((a[j]=a[j+1]))
				((a[j+1]=temp))
			fi
		done
		
	done
	echo "THE SORTED ARRAY IS "
	echo ${a[*]}
}
until((ch==3))
do
	echo "MENU"echo "1.BUBBLE SORT 2.SELECTION SORT 3.EXIT "
	echo "ENTER THE CHOICE "
	read ch
	case $ch in
	1)bubble;;
	2)selectsrt;;
	3) exit 0;;
	*) echo "WRONG CHOICE "
	exit 0;;
	esac
done

