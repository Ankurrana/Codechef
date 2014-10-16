import sys
def power(a,p,mod):
	res=1
	while p:
		if p & 0x1: res = (res*a)%mod
		a=(a*a)%mod
		p >>= 1
	return res


t=int(input())
for i in range(0,t):
	x,m,n=map(long,raw_input().split())
	n=n*(x-1)
	print x
	print n

	res=((power(x,m+1,n)-1)/(x-1))%n
	print res%(n/x-1)

sys.exit(0)
