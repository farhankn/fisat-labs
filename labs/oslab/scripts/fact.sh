#!bin/bash
fact()
{
if(($1==0))
then
res=1
else
expr=$(($1-1))
fact $expr
res=$((res*($1)))
fi
}
echo 'Enter Number'
read num
fact $num
echo Factorial is $res
#output
#00413@user:/mnt/00413/os$ bash fact.sh
#Enter Number
#5
#Factorial is 120


