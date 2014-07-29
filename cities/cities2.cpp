#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=e ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

typedef long long int lli;

class Edge{
public:
	int w,v;
	bool istrain;
	Edge();
	Edge(int _w, int _v, bool _istrain):w(_w),v(_v),istrain(_istrain){}
};

class Node{
public:
	lli d;
	bool isAdded;
	vector< Edge > AL; // first: city , weight
	Node(){d = 1e14;isAdded = false;}
	void push(Edge e){ this->AL.push_back(e); }
};

Node N[100001];

struct comp {
	bool operator()(int a ,int b){
		return N[a].d > N[b].d;
	}
};

int main(){
	ios::sync_with_stdio(false);
	lli i,j,t,n,m;
	lli p,q,k,z,l;
	get(n); get(m); get(k);
	iterate(m){
		get(p); get(q); get(z);
		N[p].push(Edge(q,z,false));
		N[q].push(Edge(p,z,false));
	}
	iterate(k){
		get(p); get(z);
		N[1].push(Edge(p,z,true));
	}

	vector< Edge >::iterator it;

	priority_queue< int , vector< int > ,comp > pq;



	pq.push(1);

	int ans = k;

	while(!pq.empty()){
		int u = pq.top(); pq.pop();
	 	N[u].isAdded = true;

	}



	// while(!pq.empty()){

	// }

	return 0;
}




