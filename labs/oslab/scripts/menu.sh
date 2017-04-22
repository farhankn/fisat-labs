#!/bin/bash
while((ch!=3))
do
	echo '1.Bubble sort'
	echo '2.Selection sort'
	echo '3.Exit'
	echo 'Enter the choice: '
	read ch
	case $ch in
	1)	echo 'Enter the limit: '
		read lim
		echo 'Enter the numbers: '
		for((i=0;i<lim;i++))
		do
			read a[i]
		done
		i=0
		for((i=0;(i<lim);i++))
		do
			for((j=0;j<(lim-1);j++))
			do
				if((a[j]>a[j+1]))
				then
					((t=a[j]))
					((a[j]=a[j+1]))
					((a[j+1]=t))
				fi
			done
		done
		echo 'Sorted array is'
		for((i=0;i<lim;i++))
		do
			echo ${a[i]}
		done
		;;
	2)	echo 'Enter the limit: '
		read lim
		echo 'Enter the numbers: '
		i=0
		j=0
		for((i=0;i<lim;i++))
		do
			read a[i]
		done
		for((i=0;i<(lim-1);i++))
		do
			((min=a[i]))
			((loc=i))
			for((j=j+1;j<lim;j++))
			do
				if((a[j]<min))
				then
					((min=a[j]))
					((loc=j))
				fi
			done
			if((loc!=$i))
			then
				((t=a[loc]))
				((a[loc]=a[i]))
				((a[i]=t))
			fi
		done
		echo 'Sorted array is'
		for((i=0;i<lim;i++))
		do
			echo ${a[i]}
		done;;
	3)	exit
		;;
	*)echo 'Invalid choice'
	esac
done



