#!bin/bash
echo 'Enter the number'
read num
i=0
sum=0
((num1=num))
((num2=num))
while((num>0))
do
((rem=num%10))
((num=num/10))
((i=i+1))
done
while((num1>0))
do
((rem=num1%10))
((num1=num1/10))
res=1
j=1
while((j<=i))
do
((res=res*rem))
((j=j+1))
done
((sum=sum+res))
done
if((sum==num2))
then
echo $num2 is an armstrong number
else
echo $num2 is not an Armstrong number
fi


#output
#00413@user:/mnt/00413/os$ bash arms.sh
#Enter the number
#141
#141 is not an Armstrong number
#00413@user:/mnt/00413/os$ bash arms.sh
#Enter the number
#153
#153 is an armstrong number
#00413@user:/mnt/00413/os$ 
#00413@user:/mnt/00413/os$ bash arms.sh
#Enter the number
#1111
#1111 is not an Armstrong number


