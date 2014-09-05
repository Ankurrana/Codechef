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


bool exists(int limitx, int limity , int x, int y){
	if(x>=0 && x<limitx && y>=0 && y<limity) return true;
	return false;
}


lli solve(){
	lli a, b,c,d,i,j;
	lli n;
	string mat[101];
	cin >> n;

	rep(n,i) cin >> mat[i];

	rep(n,i){
		rep(n,j){
			int oes = 0;
			if( exists(n,n,i-1,j) && mat[i-1][j] == 'o' ) oes++;
			if( exists(n,n,i+1,j) && mat[i+1][j] == 'o' ) oes++;
			if( exists(n,n,i,j-1) && mat[i][j-1] == 'o' ) oes++;
			if( exists(n,n,i,j+1) && mat[i][j+1] == 'o' ) oes++;

			if(oes%2 != 0) return false;

		}
	}

	return true;
}

 int main(){
 	lli i,j,k,l,p,q,x,y;

 	if(solve()) cout << "YES";
 	else cout << "NO";

	return 0; 	
 }




