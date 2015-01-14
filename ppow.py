import sys;
def sum_digits3(n):
   r = 0
   while n:
       r, n = r + n % 10, n / 10
   return r

sys.stdout.write("[")
for x in range(1,9):
	for y in range(1,10):
		ans=sum_digits3(x**y);
		sys.stdout.write(str(ans))
		sys.stdout.write(',')

sys.stdout.write("]")