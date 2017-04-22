
clear


c=1
while((c==1))
do
    echo " How many elements : "
    read n
    
    echo " Enter the elements "
    
    for((i=0;i<n;i++))
    do
	read a[i]
    done
    
    

    echo " Type 1 for bubblesort , 2 for selection sort "
    
    read opt
    
    if((opt==1))
    then
	echo "Bubble Sort"
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
    else
	
	echo "Selection Sort"
	for((i=0;i<n;i++))
	do
	    
	    min=$i
	    
	    for((j=(i+1);j<n;j++))
	    do
		if((a[j]<a[min]))
		then
		    min=$j
		fi
	    done
	    
	    temp=$((a[min]))
	    a[min]=$((a[i]))
	    a[i]=$temp
	    
	done
    fi
    
    echo ${a[*]}


    echo "Press 1 to continue "
    read c

done