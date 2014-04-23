#include "iostream"
#include "cstdio"
#include "cmath"
using namespace std;

#define get(n) scanf("%lld",&n)
typedef long long int lld;


#define iterate(n) for(lld i = 0;i < (n);i++)


void sieve( lld *a, lld n){
	 lld i, j;
 
	for(i=2; i<=n; i++)
		a[i] = 1;  //assuming 1 for prime, initially all are considered prime
	for(i=2; i<=n; i++){
		if(a[i] == 1){
			for(j=i; (i*j)<=n; j++)
				a[(i*j)] = 0;
		}
	}

} 

int main(){
	lld i,j,l,t,k;
	lld a[100001];
	lld primes[100001];
	lld p_count = 0;
	lld lower,higher;
	sieve(a,100001);


	lld testcaseprimes[100010];


	iterate(100001){
		if(a[i])
			primes[p_count++] = i; 
	}

	

	scanf("%lld",&t);

	while(t--){		 
		scanf("%lld%lld",&lower,&higher);
		if(lower == 1)
			lower++;
		lld diff = higher - lower + 1;

		for(i=0;i<=diff;i++)
			testcaseprimes[i] = 1; 


		for(lld i=0;i<p_count;i++){
			k = ceil((double)lower/primes[i]);
			if( k == 1 )
					k++;
			while(k*primes[i]<=higher){
				// cout << primes[i] << " Indexes deleted = " << k*primes[i] - lower << " which represents " << k*primes[i] << endl;
				testcaseprimes[k*primes[i] - lower] = 0;
				k++;
			}



		}

		for(j=0;j<diff;j++){
			if(testcaseprimes[j] == 1)
				printf("%lld\n",j+lower);
		}

	}	
	
	return 0;
}
