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
	lli i,j,t,n;
	lli p,q,k,z,l;
	lli dp[100010];
	lli f[100010] = {0};
	lli max = 0;
	get(n);
	int a;
	iterate(n){
		get(a);
		f[a]++;
		if(max < a) max = a; 
	}	

	dp[max] = f[max] * max;
	for(i=max-1;i>0;i--){
		if( dp[i+1] > dp[i+2] + f[i]*i ) dp[i] = dp[i+1];
		else dp[i] = dp[i+2] + f[i]*i;
	}

	printf("%lld\n",dp[1]);

	return 0;
}




