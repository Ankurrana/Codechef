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

int p[25][25];
int dp[25][210];
int M,C;

int solve(int g,int m){
	int i,j,k;

	// cout << "g = "  << g <<  "  m = " << m << endl; 

	if(g == C) return m;
	if(dp[g][m]!=-1) return dp[g][m];

	int mini = 100000000;

	for(i=1;i<=p[g][0];i++){
		if(m>=p[g][i]) mini = min(mini,solve(g+1,m-p[g][i]));
	}
	dp[g][i] = mini;
	return dp[g][i];
}



int main(){
	lld i,j,t,n;
	lld q,k,z,l;


	get(t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		get(M);
		get(C);
		iterate(C){
			get(p[i][0]);
			Diterate(j,1,p[i][0]){
				get(p[i][j]);
			}
		}
	
		int ans = M - solve(0,M);
		if(ans>=0) p(ans);
		else printf("no solution\n");

	}
	return 0;
}

