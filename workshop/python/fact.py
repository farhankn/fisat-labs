def pow(num):
	if num ==0:
		return 1
	else:
		return 2*pow(num-1)

print pow(565)
