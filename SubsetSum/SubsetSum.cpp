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
#define forall(V) for_each(V.begin(),V.end(),func); //Define func for this macro


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

bool dp[100011][111];
int a[111];
int i,j,t,n;
int p,q,k,z,l;
int maxsum = 0;


void solve(){

	maxsum = 0;
	get(n);
	dp[0][0] = true;


	for(i=1;i<=n;i++){
		get(a[i]);
		dp[0][i] = true;
		maxsum += a[i];
	}


	for(i=1;i<=maxsum;i++){
		dp[i][0] = false;
	}

	for(i=1;i<=maxsum;i++){
		for(j=1;j<=n;j++){
			dp[i][j] = dp[i][j-1];
			if( a[j] <= i){
				dp[i][j] = max(dp[i][j],dp[i-a[j]][j-1]);
			}
		}
	}

	long long ans = 0;
	for(i=1;i<=maxsum;i++){
		if(dp[i][n]) ans += i;
	}	

	printf("%lld\n",ans);

}


int main(){
	int t;
	int a[101];
	int Max = 0;

	get(t);
	while(t--){
		solve();
	};

	
	return 0;
}

