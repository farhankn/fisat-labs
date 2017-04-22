read s

flag=0
length=${#s}
sum=0
rev=""

for((i=0;i<length;i++))
do
    r=${s:length-i-1:1}
    rev="$rev$r"
    sum=$((sum + r))
done

echo "Reverse : $rev"

echo "Sum is $sum"
