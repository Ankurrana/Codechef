#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++);
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a));
#define d(a) printf(" (a) : "%lld\n,(lld)a);
#define dv(a,n) iterate(n) { printf("(a)[%d] = %lld\n",(int)i,a[i]) };

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

lld power(lld a , lld b,lld MOD){
	/*  Define MOD as a PreProcessor or remove from this function if it aint required  */
	long long ans = 1;
	while(b){ 
		if( b&1 ) 
			ans = (ans * a);
		if(ans > MOD)  ans %= MOD;
		a = (a * a);
		if(a > MOD)  a %= MOD;
		b >>= 1;				
	}
	return ans;
}

lld modInverse(lld a , lld m){
	/*  
	 #1 This modMultiplicative method uses Little Fermats theorem for finding Multiplicative Inverse 
		which requires m to be prime ( not just coprime to a ). If m is not prime but co-prime use 
		Eulers Extended algorithm.
	 #2 define MOD equal to m
	*/
	return power(a,m-2,m);
}



lld factmod(lld k , lld mod){   //finds a!%mod
	if(k>=mod) return 0;
	lld q = 1;
	for(lld i = k+1 ; i<=mod-1 ; i++) q = (i * q)%mod; 
	lld ans = modInverse(q,mod);
	ans = -1 * ans + mod;
	ans %= mod; 

	return ans;
}

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	get(t);
	while(t--){
		get(p);
		get(q);
		p(factmod(p,q));
	}
	return 0;
}

