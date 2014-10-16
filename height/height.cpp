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


class MyContainer{
public:
	int k;
	int index;
	MyContainer(int _i, int _k){
		index = _i;
		k = _k;
	}
};

vector< MyContainer > a; 


class compare{
public:
	bool operator()( const MyContainer a  ,const MyContainer b) const{
		return a.k < b.k;
	}
};


int main(){
 	lli i,j,k,l,p,q,x,y,n,d;
 	cin >> n;
 	cin >> d;	
 	vi dp(n,0);  /* It stores the lenghts ending at this index */
 	priority_queue< MyContainer , vector< MyContainer > ,compare > priQ; 

 

 	rep(n,i) {
 		cin >> k;
 		a.pb( MyContainer(i+1,k));
 	} 

 	priQ.push(a[0]);
 	dp[0] = -1;
 	dp[1] = 1;


 	for(i=1;i<n;i++){
 		int k = a[i].k;
 		lower_bound(priQ.begin(),priQ.end(),MyContainer(0,k-d))
 	}


	return 0; 	
 }




