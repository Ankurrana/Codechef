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


int a[100];
int dp[100]; // the axximum cost of cutting a rod of legnth 


int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	ios_base::sync_with_stdio(false);
	get(n);
	Diterate(i,1,n){
		get(a[i]);
	}
	dp[1] = a[1] ; //Bcoz it cannot be cut.
	dp[0] = 0;
	for( k = 2; k <= n;k++){
		int maxi = -1000;
		for(p = 1; p<=(k - k/2);p++){
			 maxi =  max(maxi, max(a[k],dp[p] + dp[k-p]));
		}
		dp[k] = maxi;
		printf("dp[%d] = %d\n",(int)k,dp[k]);
	}



	return 0;
}

