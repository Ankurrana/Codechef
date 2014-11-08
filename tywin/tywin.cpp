#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define show(a) tr(a,it){ cout << *it << endl; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)


template < typename T >
inline void geta(T *a){
	T n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	*a = n*s;
}



class node{
public:	
	int data; /* This data can be anything , just add variables in this class */
	int total;
	vector< pair< int , int > > AL; /* Ajjacency list , (adjacent node, weight )  */ 
	int p;
};

class Graph{
public:
	int N; /* total number of nodes in the graph*/
	vector< node > nodes;
	Graph(int n){ N = n;nodes.resize(n+1);} /* 1 indexed */
	void add(int u, int v,int w = 1){
		nodes[u].AL.push_back( make_pair(v,w) );
		nodes[v].p = u;  /*  Comment this line if directed graph */
	}+
	int dfs(int s){
		int sum = nodes[s].data;
		vector< pair< int , int > >::iterator it; /* Ajjacency list , (adjacent node, weight )  */ 
		for( it = nodes[s].AL.begin();it!=nodes[s].AL.end();it++){
			sum += dfs(it->first);
		}
		return nodes[s].total = sum;
	}

	int update(int s, int x){
		int diff = x - nodes[s].data;
		nodes[s].data = x;
		nodes[s].total += diff; 
		while(s!=1){
			s = nodes[s].p;
			nodes[s].total += diff;
			// cout << "Updated " << s << endl;
		}
	}

	int query(int s){
		return nodes[s].total;
	}


};	




int main(){
	lld n,m,i,j,l,r,k,p,d;
	
	// Graph g(4);
	// g.nodes[1].data = 1;
	// g.nodes[2].data = 4;
	// g.nodes[3].data = 3;
	// g.nodes[4].data = 2;

	// g.add(1,2);
	// g.add(1,3);
	// g.add(3,4);

	// g.update(4,0);
	// cout << g.dfs(1) << endl;

	get(n); get(m);

	Graph g(n);

	rep(n,i){
		get(k);
		g.nodes[i+1].data = k;
	}
	lld a,b;

	rep(n-1,i){
		get(a);
		get(b);
		g.add(a,b);
	}

	g.dfs(1);	
	string que;

	while(m--){
		char c;
		scanf("%c",&c);
		if( c == 'U') {
			get(a);
			get(b);
			g.update(a,b);
		}else{
			get(a);
			printf("%d\n",g.query(a) );
		}
	}

	return 0; 	
 }














