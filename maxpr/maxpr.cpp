#include "iostream"
#include "cstdio"

using namespace std;
#define lld long long int

#define MOD 1000000007

lld power(lld a, lld b, lld mod){
	lld ans = 1;
	while(b > 0){ 
		if(b&1) 
			ans = (ans * a)%mod; 
		a = (a*a)%mod; 
		b >>= 1;
	                                           }
	return ans;
}

lld dp[110][111];
lld a[200010];
lld dp2[111][111];


int main(){
	lld n;
	lld d,j,i,ans = 0;
	lld f[101] = {0}; //frequency

	lld t;
	scanf("%lld",&t);
	while(t--){
		ans = 0;
		for(i=0;i<=100;i++){
			for(j=0;j<=100;j++){
				dp[i][j] = 0;
				dp[i][j] = 0;
			}
			f[i] = 0;
		}

		scanf("%lld",&n);
		for(i=0;i<n;i++)
				scanf("%lld",&a[i]);

			f[a[0]]++;

		for(i=1;i<n;i++){
			for(d=1;d<a[i];d++){
				dp[a[i]][d] = (dp[a[i]][d] + f[a[i]-d] + dp[a[i]-d][d])%MOD;
			}
			for(d=1;d<=(100-a[i]);d++){
				dp2[a[i]][d] = (dp2[a[i]][d] + f[a[i]+d] + dp2[a[i]+d][d])%MOD;
			}
			f[a[i]]++;
		}


		for(i=1;i<=100;i++){
			for(j=1;j<=100;j++){
				// printf("%lld\t",dp[i][j]);
				ans = (ans +  dp[i][j])%MOD;
				ans = (ans +  dp2[i][j])%MOD;

			}
			// printf("\n");
		}
		for(i=1;i<=100;i++){
			ans = (ans + power(2,f[i],MOD) - 1 + MOD)%MOD;
		}


		printf("%lld\n",(power(2,n,MOD)-1 - ans + MOD)%MOD );
	}
	return 0;
}