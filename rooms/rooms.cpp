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
 	lli n,a,b;

 	get(n);
 	get(a);
 	get(b);

 	lli area1;
 	lli area2;

 	lli a1,b1;
 	a1 = max(a,n);
 	b1 = max(b,6);

 	area1 = a1*b1;


 	lli a2 = max(a,2*n);
 	lli b2 = max(b,3*n);

 	area2 = a2 * b2;


 	cout << min(area1,area2);




	return 0; 	
 }




