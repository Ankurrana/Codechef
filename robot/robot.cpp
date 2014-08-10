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
bool iseven(lld a){return !(a&1);}
bool isodd(lld a){return (a&1);}
bool ispbetweenab(lld p,lld a,lld b){
	if(a>b) swap(a,b);
	if(a<=p && p<=b) return true;
	return false;
}

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	lld x,y;
	bool ans = false;
	






	get(t);


	while(t--){
		ans = false;
		get(x);
		get(y);



		if(x>0 && isodd(x) && ispbetweenab(y,1-x,x+1)){
			ans |= true;
		}
		// p(ans);
		if(x<0 && iseven(x) && ispbetweenab(y,-x,x)){
			ans |= true;
		}
		// p(ans);

		if(iseven(y) && y<0 && ispbetweenab(x,-y,y+1)){
			ans |= true;
		}
		// p(ans);/

		if(iseven(y) && y>0 && ispbetweenab(x,y-1,-y)){
			ans |= true;
		}

		// p(ans);/

		if(x == 0 && y == 0){
			ans |= true;
		}
		if(ans){
			printf("YES\n");
		}else{
			printf("NO\n");
		}


	}
	return 0;
}

