#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
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
 	lli n,i,j,k,l,p,q,x,y;
 	get(n); get(k);
 	vi a;
 	rep(n,i) get(p) , a.pb(p);

 	int ans = 0;
 	rep(n,i){
 		if(a[i]>=a[k-1] &&  a[i]>0) ans++;
 		else break;
 	}

 	cout << ans;

	return 0; 	
 }




