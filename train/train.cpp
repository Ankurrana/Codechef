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
	int max = 0;
	int current_Passengers = 0;
	rep(n,i){
		get(p); get(q);
		current_Passengers -= p;
		current_Passengers += q;
		if(current_Passengers > max) max = current_Passengers;
	}	

	cout << max;

	return 0; 	
 }




