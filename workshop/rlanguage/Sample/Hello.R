data=read.csv('hhp.csv')
plot(data[,1],data[,3])
model=lm(price~size+no_bedrooms,data)
coeff=coefficients(model)
coeff[1]
coeff[2]
abline(a=coeff[1],b=coeff[2],col=3)
given_size=4300
price_predicted=coeff[1]+coeff[2]*given_size
print(price_predicted)


model=lm(price~size+no_bedrooms,data)
coeff1=coefficients(model)
given_size=43000
no_rooms=2
price_predicted1=coeff1[1]+coeff1[2]*given_size+coeff1[3]*no_rooms
print(price_predicted1)