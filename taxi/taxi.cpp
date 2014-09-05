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
	get(n);
	int a[5] = {0};
	rep(n,i){
		get(k);
		a[k]++;
	}

	int ans = a[4];
	if(a[3] > 0) ans += a[3]; a[1] -= a[3];
	if(a[2] > 0) ans += a[2]/2; a[2] = a[2]%2;
	if(a[2] > 0) { 
		ans += 1;
		a[1] -= 2;
	}
	if(a[1] > 0) ans += a[1]/4;
	if(a[1] > 0 && a[1]%4 > 0) ans++;

	cout << ans;




	return 0; 	
 }




