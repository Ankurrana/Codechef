#include "bits/stdc++.h"
#include "string"
#include "climits"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=e ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }
#define mp(a,b) make_pair(a,b);
typedef long long int lli;


class Node{
public:
	lli distance; // the min distandce required to reach this node from the source
	bool isadded;
	int parent; 
	bool istrain;
	vector< pair< int,int > > AL; // first : the adjacent node , second  :  the weight_uv;
	Node(){
		istrain = false;
		isadded = false;
		distance = 1e14L;		
	}
};


struct comp{
	bool operator()(pair< int, int > a, pair< int, int > b){
		return a.second > b.second;
	};
};

int main(){
	ios::sync_with_stdio(false);
	lli i,j,t,n;
	lli p,q,k,z,l,m;


	Node N[100001];
	priority_queue < pair< int, int > , vector< pair< int,int > >,comp > pq;
	get(n); get(m); get(k);
	Diterate(i,1,m){
		get(p);
		get(q);
		get(z); 
		N[p].AL.push_back(make_pair(q,z)) ;
		N[q].AL.push_back( make_pair( p,z ) );
	}

	Diterate(i,1,k){
		get(p); get(z);
		N[1].AL.push_back(make_pair(p,z));
		N[p].istrain = true;
	}

	/* Priority Queue just maintains the next ndde that can be reached with its distance */
	N[1].distance = 0;	
	pq.push( make_pair(1,N[1].distance) );

	while(!pq.empty()){
		pair<int,int> current = pq.top(); pq.pop();
		int u = current.first;

		N[u].isadded = true;
		vector< pair<int,int> >::iterator it; 

		for(it = N[u].AL.begin(); it!= N[u].AL.end();it++ ){
			int v = it->first; int weight_uv = it->second;

			if(  N[it->first].isadded == false ){
				if( N[v].distance > N[u].distance + weight_uv  ){
						N[v].distance = N[u].distance + weight_uv;
						N[v].parent  = u;
				}
					pq.push( make_pair(v,N[v].distance) );
			}

		}
	}

	int w,ans = 0;
	for(i=1;i<=n;i++){
		// cout << i << " distance from Node 1  " << N[i].distance << endl;	
		if(N[i].parent == 1 && N[i].istrain) ans++;
	}

	p(k-ans);
	// iterate(k){
	// 	// cout << i+1 << " distance from Node 1  " << N[i+1].distance << endl;
	// 	get(q);
	// 	get(w);
	// 	// cout << q  << " : " << N[q].distance << endl;
	// 	if(N[q].distance <= w)
	// 		ans++;
	// }
	cout << ans << endl; 
}




