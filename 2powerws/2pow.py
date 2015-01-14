n=input()
i=0
while n>0:
	if n&1:print(1<<i)
	i+=1
	n>>=1
