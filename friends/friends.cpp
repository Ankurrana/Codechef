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
bfs
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
	char str[2010][2010];
	bitset<2010> B[2010];	
	ios_base::sync_with_stdio(false);
	get(n);

	Diterate(i,1,n){
		scanf("%s",str[i]);
		Diterate(j,1,n) {
			if(str[i][j-1] == '1'){
				B[i].set(j);
			}
		}
	}

	lld ans = 0;
	Diterate(i,1,n){
		Diterate(j,i+1,n) {
			if(B[i][j] == false){
				if((B[i]&B[j]).any()) ans+=2;
			}
		}
	}

	p(ans);
	return 0;	
}

