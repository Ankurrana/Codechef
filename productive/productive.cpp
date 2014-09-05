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

lli solve(){
	lli i,j,k,l,n;
	lli ans = 0;	
 	vector < pair< int, pair< int,int > > > Nodes;	
	int row[101] = {0};
	int col[101] = {0};
	get(n);

	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));

	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			get(k);
			Nodes.push_back( make_pair(k, make_pair(i,j) ));
		}
	}
	sort(Nodes.rbegin(),Nodes.rend());


	


	for(i=0;i<n*n;i++){
		int c = Nodes[i].second.first;
		int r = Nodes[i].second.second;

		if(row[r] == 0 && col[c] == 0){
			row[r] = 1;
			col[c] = 1;
			ans += Nodes[i].first;
		}
	}

	return ans;
 		
}


// lli solve(){
// 	lli i,j,k,l,m,n;
// 	lli ans = 0;
// 	lli mat[110][110];
// 	get(n);
// 	lli maxi = 0;

// 	rep(n,i){
// 		rep(n,j){
// 			cin >> mat[i][j];
// 		}
// 	}

// 	rep(n,i){
// 		maxi = 0;
// 		rep(n,j){
// 			if( mat[j][i] > maxi ) 
// 				maxi = mat[j][i];
// 		}
// 		ans += maxi;
// 	}

// 	return ans;
// }

 int main(){
 	lli i,j,k,l,p,q,x,y,t;

 	// cout << solve();
 	// cout << solve();
 	get(t);
 	while(t--){
		cout << solve() << endl;
 	}	

	return 0; 	
 }




