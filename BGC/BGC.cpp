#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++);
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a));
#define d(a) printf(" (a) : %lld",(lld)a);
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

bool iscalculated[1000001];
lld dp[1000001];




lld getmax(lld n){
	if( n <= 1000000 ){
		if(iscalculated[n] == true){
			return dp[n];
		}else{
			lld ans = max( n, getmax(n/2) + getmax(n/3) + getmax(n/4) );
			iscalculated[n] =  true;
			dp[n] = ans;
			return ans;
		}
	}else{
		lld ans = max( n , getmax(n/2) + getmax(n/3) + getmax(n/4) );
		return ans;
	}
}

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;

	dp[0] = 0;
	iscalculated[0] = 1;
	dp[1] = 1;
	iscalculated[1] = 1;
	dp[2] = 2;
	iscalculated[2] = 1;

	for(i=3;i<=10;i++){
		dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4] );
		iscalculated[i] = true; 
	}


	while( scanf("%lld",&q) > 0 ){
		p(getmax(q));
	}	
	return 0;
}

