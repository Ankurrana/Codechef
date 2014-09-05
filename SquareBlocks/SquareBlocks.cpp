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
// #define print(a) printf("%lli\n",(lli)a);


lli solve(){
	lli ans;
	lli a,b,c;
	get(a); get(b); get(c);
	ans = (a/c) + ((lli)((a%c)>0));
	ans = ans * ((b/c) + (lli)( (b%c) > 0));
	return ans;
}

 int main(){
	ios_base::sync_with_stdio(0);
	lli i,j,k,l,p,q,x,y;
	// cout << solve();
	// print(solve());

	cout << solve();

	return 0; 	
 }




