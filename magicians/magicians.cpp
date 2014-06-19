#include "iostream"
#include "cstdio"

using namespace std;

void solve(int n){
	int dp[110][110] = {0};
	int a[110][110];
	int i,j,k,l;

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);	

	dp[1][1] = 0;

	for(i=1;i<=n;i++){
		dp[1][i] = dp[1][i-1] + a[1][i];
		dp[i][1] = dp[i-1][1] + a[i][1];
	}

	for(i=2;i<=n;i++)
		for(j=2;j<=n;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + a[i][j];
		}




	// for(i=1;i<=n;i++){
	// 	for(j=1;j<=n;j++)
	// 		printf("%d\t", dp[i][j]);
	// 	printf("\n");
	// }

	if( dp[n][n] < 0 ){
		printf("Bad Judges\n");
	}else{
		printf("%f\n",(double)dp[n][n]/((n<<1)-3));
	}

}


int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}