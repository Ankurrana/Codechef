#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define p(a) printf("%lld\n",(lld)(a))
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

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


int sieve(lld n , bool *primesBitset){  
 	/* @n : The number upto which primes are to be generated */
 	/* @primeList  :  Pointer to a int array where the result is to be stored*/
 	/* returns the number of primes from 2 to n */
 	/* You can also obtain the bitset (for O(1) checking ) by makinbg neccessary changes  */
 	lld i, j , count = 0;
	primesBitset[0] = 1;
	primesBitset[1] = 1; // 1 is not a prime
	for(i=2; i<=n; i++){
		if(primesBitset[i] == 0){
			for(j=i; (i*j)<=n; j++)
				primesBitset[(i*j)] = 1;
		}
	}

}




int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	lld dp[1000001] = {0};

	bool bitset[100001]; 

	sieve(10001,bitset);

	// iterate(10)
	// 	cout << bitset[i] << endl;

	for(i=1;i<=10001;i++){
		if(bitset[i] == 0){
			dp[i] = dp[i-1] + i;
		}else{
			dp[i] = dp[i-1];
		}
	}

	// iterate(10){
	// 	p(dp[i]);
	// }


	get(t);
	while(t--){
		get(k);
		p(dp[k] - dp[27]);
	}

	return 0;
}

