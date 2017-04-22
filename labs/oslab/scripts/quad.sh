#!bin/bash
echo enter coefficient a
read a
echo enter coefficient b
read b
echo enter coefficient c
read c
d=$(((b*b)-(4*a*c)))
if((d>0))
then
r1=$(((-b+sqrt(d))/(2*a)))
fi
echo $r
