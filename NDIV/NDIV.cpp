#include "bits/stdc++.h"
#include "string"
#include "cmath"

using namespace std;

typedef long long int lld;

#define getw getchar_unlocked
#define get(a) geta(&a)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vii vector< long long >
#define vit vector<int>::iterator
#define viit vector<long long>::iterator
#define pb push_back
#define all(V) V.begin(),V.end()

template < typename T >
inline void geta(T *a){
	T n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	*a = n*s;
}


vector< int > sieve(long long n){
	long long i;  
	bitset< 1000001 > isPrime;
	isPrime.set();
	isPrime[0] = 0;
	isPrime[1] = 0; // Both are not primes
	long long sqroot = sqrt(n)+1;

	for(i=4;i<=n;i=i+2) isPrime[i] = 0; // first remove all the even numbers

	for(i=3;i<=sqroot;i++){
		if( isPrime[i] ){
			long long k = i + i + i;
			while( k <= n ){
				isPrime[k] = 0;
				k = k + (i<<1);
			}
		}
	}

	vector<int> ans;
	for(i=2;i<=n;i++){
		if(isPrime[i]) ans.push_back(i);
	}
	return ans;

}
vi primes;
lld limit = 0;


inline lld NumFactors(lld a){
	if(a == 1) return 1;
	lld i,j,k;
	int size = primes.size();
	int ans = 1;
	k = a;

	for(i=0;i<size;i++){
		if(primes[i] * primes[i] > a) break;
		int e = 0;
		while(k > 1){
			if(k%primes[i] == 0){
				e++;
				k = k/primes[i];
			}else{
				break;
			}
		}

		ans = ans*(e+1);
		if(ans > limit) break;
	}	
	if( k > 1) return ans<<1;
	return ans;
}



int main(){
	lld i,j,t,n;
	lld q,k,z,l;
	lld a,b;
	get(a);
	get(b);
	get(n);
	vit it;

	limit = n;

	primes = sieve( sqrt(b)+1 );



	lld ans = 0;

	for(i = a;i<=b;i++){
		if( NumFactors(i) == n) 
			ans++;
	}	

	printf("%lld",ans);


	return 0;
}

