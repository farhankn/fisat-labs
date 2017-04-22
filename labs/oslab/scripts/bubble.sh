echo "length of array"
read n



for((i=0;i<n;i++))
do
    read a[i]
done

bubble=1

while((bubble))
do
    bubble=0
    for((i=0;i<(n-1);i++))
    do
	#echo $i
	#echo $((a[i]))
	#echo $((a[i+1]))
	if((a[i]>a[i+1]))
	then
	    echo "swapped $((a[i])) and $((a[i+1]))"
	    temp=$((a[i]))
	    a[i]=$((a[i+1]))
	    a[i+1]=$temp
	    bubble=1
	fi
    done
    echo ${a[*]}
done

echo ${a[*]}
