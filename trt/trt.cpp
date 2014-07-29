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

int a[2001];
int dp[2010][2010];
int n;
int maxBetween(int count,int l, int r){
	if(l>r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	if( l == r) return  dp[l][r] = count * a[l];
	else return dp[l][r] = max( count*a[l] + maxBetween(count+1,l+1,r) , count*a[r] + maxBetween(count+1,l,r-1) );
}







int main(){
	ios_base::sync_with_stdio(false);
	get(n);
	memset(dp,-1,sizeof(dp));
	Diterate(i,1,n) get(a[i]);
	cout << maxBetween(1,1,n);
	
	return 0;
}

