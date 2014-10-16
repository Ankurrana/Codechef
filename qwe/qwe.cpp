#include "bits/stdc++.h"
using namespace std;

typedef vector<long long int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lli;

#define get(a) cin >> a 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,i){ cout << *i << endl; }
#define rep(n,i) for(i=0;i<n;i++)

 int main(){
 	ios_base::sync_with_stdio(false);
 	lli i,j,k,l,p,q,x,y,a,b;
 	vi dp;
 	lli t;
 	cin >> t;
 	cin >> k;
 	dp.push_back(0);

 	lli n = 100010;

 	lli mod = 1000000007;

 	for(i=1;i<=k-1;i++){
 		dp.pb(1);
 	}	

 	dp.push_back(2);
 	for(i=k+1;i<=n;i++){
 		dp.push_back( (dp[i-k] + dp[i-1])%mod);
 	}

 	for(i=1;i<=n;i++){
 		dp[i] = (dp[i] +  dp[i-1])%mod;
 	}

 	rep(t,i){
 		cin >> a >> b;
 		cout << (dp[b] - dp[a-1] + mod)%mod << endl;
 	}

	return 0; 	
 }




