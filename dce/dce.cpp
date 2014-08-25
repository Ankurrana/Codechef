#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define pb push_back

cpp
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

lld getmsbset(lld x){
	lld y = x;
	int k = 1;
	while(k<=32){
		y = y | (y >> k);
		k <<= 1;
	}
	return (y+1)>>1; 
}

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l,a;

	get(t);
	while(t--){
		get(a);
		printf("%lld\n",getmsbset(a) );
	}
	return 0;
}

