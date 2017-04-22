


n = input()
sum=valid(n)
print sum



def valid(n):
	for i in xrange(0,n):
		if isvalid(i):
			sum+=i
			if ((sum<n)&(sum>2)):
				if(isvalid(sum)):
					count=count+1
	return count



def isvalid(num):
	if num<2:
		return 0;
	for i in xrange(2,num):
		if (num%i==0):
			return 0
	return 1



