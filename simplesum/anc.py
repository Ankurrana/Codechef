def power(b, p):
    """
    Calculates b^p
    Complexity O(log p)
    b -> double
    p -> integer
    res -> double
    """
    res = 1

    while p:
        if p & 0x1: res *= b
        b *= b
        p >>= 1

    return res
				
t=int(input())
ans=""
for i in range (0,t):
	x,m,n=map(long,input().split())
	print x
	print m
	print n
	v = long((power(x,m+1,n)-1)/(x-1))
	v=v%n
	ans+= str(v)+"\n"
	
print (ans) 