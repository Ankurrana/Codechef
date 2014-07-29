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

int c[10];
int dp[10][10];
int solve(int i,int j){
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==j) return 0;
	if(j == i+1) return 0;
	int mini = 1e8;
	for(int k=i+1;k<j;k++){
		mini  = min(mini , solve(i,k)+solve(k,j) + c[k] - c[i] + c[j] - c[k]);
	}
	return dp[i][j] = mini;

}


int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	ios_base::sync_with_stdio(false);

	memset(dp,-1,sizeof(dp));

	c[0] = 0;
	c[1] = 25;
	c[2] = 50;
	c[3] = 100;

	p(solve(0,3));
	return 0;
}

