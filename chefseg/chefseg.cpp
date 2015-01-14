#include "iostream"
#include "cstdio"
using namespace std;

int main(){
	long long t,x,k;
	cin >> t;
	while(t--){
		cin >> x >> k ;
		long long pp = 1;
		while(pp < k) pp <<= 1;
		if(pp > k) pp >>= 1;
		double len = (double)x/pp;
		double d = len/2;
		double ans = d + len*(k-pp);
		printf("%.9f\n",k>1?ans:x/2);
	}	
	return 0; 	
 }

