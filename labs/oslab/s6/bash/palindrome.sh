#IFS=""

read s

echo $s

flag=0

length=${#s}
echo $length

mid=$((length/2)) 
echo $mid

for((i=0;i<mid;i++))
do
    if [ ${s:i:1} != ${s:length-i-1:1} ]
    then
	echo "not palindrome"
	flag=1
	exit
    fi
done

if((flag != 1))
then
    echo "Palindrome"
fi