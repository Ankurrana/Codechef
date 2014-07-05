#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
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

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	lld x,y;
	get(t);
	while(t--){
		get(x);
		get(y);

		lld ans;
		if( (x + y)%2 == 0 ){
			ans = 2*max(labs(x),labs(y));
		}else{
			ans = 1 + 2 * max(labs(x),labs(labs(y)-1));
		}
		p(ans);
	}
	return 0;
}

