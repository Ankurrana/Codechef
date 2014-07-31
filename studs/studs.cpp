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
int ranks[25];
int n;
int flag = 1;

void solve(){
	int i,j,k;
	int s[21];
	iterate(n){
		if(scanf("%d",&s[i] ) < 0){
			flag = 0; 
			return;
		}else{
			s[i] = ranks[s[i]];
		}
	}
	int dp[21];
	iterate(22) dp[i] = 1;

	int maxi = 1;



	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if( s[i] > s[j]  ){
				dp[i] = max(dp[i],dp[j] + 1);
				if(dp[i] > maxi) maxi = dp[i];
			}
		}
		// printf("dp[%d] = %d\n",i,dp[i] );
	}

	printf("%d\n",maxi);
}

int main(){
	int i,j,t;
	int p,q,k,z,l;
	
	get(n);
	int rank = 1;	
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		ranks[t] = rank++;
	}

	for(i=1;i<=n;i++) printf("rank of %d = %d\n",i,ranks[i]);


	while(flag){
		solve();
	}

	
	return 0;
}

