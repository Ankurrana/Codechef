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

class Node{
public:
	int data;
	vi AL;
	Node(){}
}N[100011];

int main(){
 	lli n,i,j,k,l,p,q,x,y;
 	get(n); get(q);
 	N[0].data = -1;

 	for(i=1;i<=n;i++){
 		get(x);
 		N[i].data = x;
 	}

 	rep(n-1,i){
 		get(x); get(q);
 		N[x].AL.pb(y);
 		N[y].AL.pb(x);
 	}

 	rep(q,i){
 		get(k);
 		if(k == 1){
 			get(x);	
 		}else{
 			get(x);
 			get(y);
 			N[x].data = y;
 		}
 	}


	return 0; 	
 }




