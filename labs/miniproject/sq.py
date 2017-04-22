m=0
l=0
num=float(input("Enter a Number: "))
h=num

while(m*m!=num):
	m=(l+h)/2
	if(m*m>num):
		h=m
		l=0
	elif(m*m<num):
		l=m
print "square root is "
print m
