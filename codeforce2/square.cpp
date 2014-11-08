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
 	lli i,j,k,l,p,q,x,y;
	lli t;
	get(t);
	int maxx = INT_MIN;
	int maxy = INT_MIN;
	int minx = INT_MAX;
	int miny = INT_MAX;
 	while(t--){
		get(p);
		get(q);
		if(p > maxx ) maxx = p;
		if(p < minx ) minx = p;
		if(q > maxy ) maxy = q;
		if(q < miny) miny = q;


	}	 
	lli len = max(maxx-minx, maxy-miny) ;

	cout << len*len << endl;	

	return 0; 	
 }




