#include "iostream"
#include "cstdio"

using namespace std;
#define getw getchar_unlocked
#define lld long long int
#define MOD 1000000007

#define get(a) a = scan();


inline int scan(){
	int n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	return n*s;
}






lld power(lld a, lld b){
	lld ans = 1;
	while(b>0){
		if(b&1){
			ans = (ans * a);
			if(ans > MOD)
				ans %= MOD;
		}
		a = (a * a);
		if(a > MOD)
				a %= MOD;
		b = b>>1;
	}
	return ans;
}



int main(){
	int t,i,j,k,l,a;
	lld dp[2][101][101] = {0};
	lld ans = 0,n=0;
	int f[101] = {0};
	int min,max;
	get(t);
	while(t--){
		min = 101;
		max = 0;
		ans = 0;
		scanf("%lld",&n);
		for(k=0;k<n;k++){
			get(a);
			f[a]++;
			if(a > max) max = a;
			if( a < min) min = a;

			for(j = min ; j<=max ; j++ ){
				if(f[j] == 0)
					continue;

				if(j<a){
					dp[0][a][a-j] = (dp[0][a][a-j] + f[j] + dp[0][j][a-j]);
					if(dp[0][a][a-j] > MOD){
						dp[0][a][a-j] %= MOD;
					}
				}else if(j>a){
					dp[1][a][j-a] = (dp[1][a][j-a] + f[j] + dp[1][j][j-a]);
					if(dp[1][a][j-a] > MOD )
						dp[1][a][j-a] %= MOD; 
				}
			}

		}

	
		// for(i=1;i<=max;i++){
		// 	for(j=1;j<=max;j++){
		// 		printf("%lld\t",dp1[i][j] );
		// 	}
		// 	printf("\n");
		// }	
		



		for(i=min;i<=max;i++){
			ans = (ans + power(2,f[i]) - 1);
			if(ans > MOD)
					ans %= MOD;

			f[i] = 0;
		}


		for(i=min;i<=max;i++){
			for(j=1;j<=max;j++){
				ans = (ans + dp[0][i][j]);

				if(ans > MOD)
						ans %= MOD;

				ans += dp[1][i][j];

				if( ans > MOD )
						ans %= MOD;

				dp[0][i][j] = 0;
				dp[1][i][j] = 0;
			}
		}


		// printf("%lld\n",ans);
		printf("%lld\n",(power(2,n) - 1 - ans  + MOD)%MOD )  ;
		ans = 0;
	}
	return 0;
}