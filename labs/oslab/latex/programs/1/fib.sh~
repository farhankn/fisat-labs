#!bin/bash
n1=0
n2=1
echo 'Enter the range'
read num
echo 'Series is:'
echo $n1
if ((num>=2))
then
echo $n2
fi
((num=num-2))
while((num!=0))
do
((n=n1+n2))
((n1=n2))
((n2=n))
((num=num-1))
echo $n
done
#output
#00413@user:/mnt/00413/os$ bash fib.sh
#Enter the range
#6
#Series is:
#0
#1
#1
#2
#3
#5
#00413@user:/mnt/00413/os$ 

