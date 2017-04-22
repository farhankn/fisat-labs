import getch

primes=[]
z=1
limit=int(input("Enter the Limit"))
for i in range(2,limit):
	primes.insert(i,1)
for i in range(2,limit):
	if (primes[i]):
		j=i
		while(i*j<limit):
			print i*j
			char = getch.getch()
			primes.insert(i*j,0)
			j=j+1
for i in range(2,limit):
	if (primes[i]):
		print i
