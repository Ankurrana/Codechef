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
 	lli a,b,n,m;

 	get(n);
 	get(m);	
 	get(a);	
 	get(b); //cost of m rides	

 	lli ans = 0;
 
 	double perride = (double)b/m;

 	if( perride > a ){
 		ans  = n * a;
 	}else{
 		ans = (n/m) * b;
 		if( b < (n%m) * a ){
 			ans += b;
 		}else{
 			ans +=(n%m) * a;
 		}


 	}


 	cout << ans;


	return 0; 	
 }



