t = raw_input();
t = int(t);
while t:
	x,m,n = raw_input().split()
	x = int(x);
	m = int(m);
	n = int(n);
	t = t-1;
	if(x==1):
		print (m+1)%n
	else:
		n *= x-1;
		ans = pow(x,m+1,n);
		ans -= 1;
		if (ans < 0): ans += n;
		ans /= (x-1);
		ans %= n;
		print ans;