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

int solve(int x,int y){
	if(x==y || (x-2 == y) ){
		if(x==y){
			if(x&1){
				return 2*x - 1;
			}else{
				return 2*x;
			}
		}else{
			return solve(x,y+2) - 2;
		}
	}else
		return -1;
}

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	get(t);
	while(t--){
		get(p);
		get(q);
		int ans = solve(p,q);

		if(p==0 && q==0){
			printf("0\n");
			continue;
		}
		if(ans > 0)
			p(ans)
		else
			printf("No Number\n");
	}
	return 0;
}

