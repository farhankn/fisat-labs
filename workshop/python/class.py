import random
import pylab
class JackFruitTree():
	def __init__(self,ctype,width,height,soil_type,name):
		self.type=ctype
		self.w=width
		self.h=height
		self.st=soil_type
		self.name=name
	def getNoOfFruits(self,month):
		return random.choice([1,2,3,4,5,5])*month

c1=JackFruitTree('Varika',12,50,'T','JYOS')
c2=JackFruitTree('Varika',12,59,'T','KORAN')
x1=[]
x2=[]
for month in range(1,13):
	x1.append(c1.getNoOfFruits(month))
	x2.append(c2.getNoOfFruits(month))

pylab.plot(x1)
pylab.plot(x2)
pylab.show()
