#IFS=""

echo "Enter string"

read string

len=${#string}

echo $len

flag=1

for((i=0;i<len;i++))
do

	if [ ${string:i:1} != ${string:len-i-1:1} ]
	then
		echo "${string:i:1} == ${string:len-i-1:1}"
		flag=0
	fi
done

if((flag==1))
then
	echo "$string is a palindrome"
else
	echo "$string is not a palindrome"
fi
