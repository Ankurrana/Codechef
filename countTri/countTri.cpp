#include "bits/stdc++.h"
using namespace std;
#define getw getchar_unlocked
#define lld unsigned long long int

template < typename T >
inline void geta(T *a){
	T n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	*a = n*s;
}

int main(){
	lld t,p;
	geta(&t);
	while(t--){
		geta(&p);
		printf("%lld\n",p*(p+2)*(2*p + 1)>>3 );
	}
	return 0;
}
