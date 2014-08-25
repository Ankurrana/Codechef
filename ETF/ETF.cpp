#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define print(a) printf("%lld\n",(lld)(a))
#define pb push_back


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

int phi[1000001];
int limit = 1000000;
void ETF(){
	int i,j,k,l;
	memset(phi,0,sizeof(phi));
	phi[1] = 1;
	for(i=2;i<=limit;i++){
		if(phi[i] == 0){
			phi[i] = (i - 1);
			for( j = i*2;j<=limit; j += i ){
				if(phi[j] == 0) phi[j] = j;
				phi[j] = (phi[j]/i)*(i-1);
			}
		}
	}
}


int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	ETF();

	get(t);
	while(t--){
		get(p);
		printf("%d\n",phi[p]);
	}
	return 0;
}

