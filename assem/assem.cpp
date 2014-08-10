#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=e ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

typedef long long int lli;

int main(){
	ios::sync_with_stdio(false);
	
	int i,j,k,n;

	int dp[100][2];
	int a[100][2];
	int t[100][2];
	
	printf("Enter the number of stations\n");
	get(n);

	printf("Enter the working time at each station first station 0  , then 1st new line and then ext station\n");
	iterate(n){
		get(a[i][0]);
		get(a[i][1]);
	}
	int p,q;

	printf("Enter staging time\n");
	get(p); get(q);

	dp[0][0] = a[0][0] + p;
	dp[0][1] = a[0][1] + q;

	printf("Enter Removal time\n");
	get(p); get(q);


	printf("Enter the time taken to tranfer item at i[k] to i+1[1^k] \n");
	iterate(n-1){
		get(t[i][0]);
		get(t[i][1]);
	}




	for(i=1;i<n;i++){
		for(j=0;j<2;j++){
			dp[i][j] = min(dp[i-1][j^1] + t[i-1][j^1] , dp[i-1][j]) + a[i][j];
		}
	}

	cout << min(dp[n-1][0] + p,dp[n-1][1] + q);

	return 0;
}




