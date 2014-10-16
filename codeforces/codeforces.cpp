#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lli;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) cin >> a
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define show(a) tr(a,it){ cout << *it << endl; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)
#define print(a) cout << a << "\n"


void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}

 int main(){
 	ios_base::sync_with_stdio(false);
	lli n,m,i,j,l,r,k,p,d;
	
	lli a,b,c,ans;	
	get(n);
	get(m);

	lli min = n/2 + n%2;
	lli max = n;

	k = (min/m);

	lli z = k*m;

	bool done = false;
	for(i=min;i<=max;i++){
		if( i%m == 0){
			print(i);
			done = true;
			break;
		}
	}

	if( !done ){
		print(-1);
	}

	
	return 0; 	
 }














