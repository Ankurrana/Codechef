#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lli;

#define get(a) cin >> a;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) i = c.begin();i!= (c).end();i++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,i){ cout << *i << endl; }
#define rep(n,i) for(i=0;i<n;i++)



lli solve(){
	lli ans,i,j,l,n,m,k,p,q;
	vi a;
	lli cum[1000000];
	cin >> n;
	rep(n,i){ 
		cin >> k;
		a.pb(k);
	} 

	sort(a.rbegin(),a.rend());

	cum[0] = a[0];

	for(i=1;i<n;i++){
		cum[i] = cum[i-1] + a[i];
	}

	a.pb(0);

	ans = cum[n-1];

	for(i=n-2;i>=0;i--){
		ans = ans + cum[i] + a[i+1];
	}
	return ans;
}

 int main(){
 	lli i,j,k,l,p,q,x,y;

 	cout << solve();
	return 0; 	
 }




