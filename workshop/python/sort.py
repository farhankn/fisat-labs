a=[5,9,8,10]
j = 0
swap = 0
for i in range(0,3):
	imin = i
	for j in range(i+1,4):
		if a[j] < a[imin]:
			imin = j
	if imin!=j:
		swap = a[i]
		a[i] = a[imin]
		a[imin] = swap	

print a
