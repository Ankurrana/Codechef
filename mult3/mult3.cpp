#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a))
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

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

int parent[5010];  //parent of the ith node;

struct Edge{
	int u;
	int v;
	lld weight;
}CEdges[20010],OEdges[20010];

int findParent(int i){  //it accpets a node and returns its representative node
	if( i == parent[i]) return parent[i];
	else{
		parent[i] = findParent(parent[i]); /*  Path Compression */
		return parent[i];
	}
};

int  myfunc(const void *a ,const void *b){
	int x = ((const struct Edge*)a)->weight;
	int y = ((const struct Edge*)b)->weight;

	return x>y;
}


lld solve(){
	lld i,j,t;
	lld p,q,k,z,l;
	int n,m1,m2;
	get(n);
	get(m1);
	get(m2);
	iterate(n+1){
		parent[i] = i;
	} 


	iterate(m1){
		get(p);
		get(q);
		get(k);
		OEdges[i].u = p;
		OEdges[i].v = q;
		OEdges[i].weight = k;
	}
	iterate(m2){
		get(p);
		get(q);
		get(k);
		CEdges[i].u = p;
		CEdges[i].v = q;
		CEdges[i].weight = k;	
	}

	qsort(OEdges,m1,sizeof(*OEdges),myfunc);
	qsort(CEdges,m2,sizeof(*CEdges),myfunc);

	int egdesadded = 0;
	lld cost = 0;
	lld totalCost = 0;
	i = 0;
	while(egdesadded <= n-1 && i<m2){
		// cout << CEdges[i].u << " " << CEdges[i].v << " " << findParent(CEdges[i].u) << " "  << findParent(CEdges[i].v) << "\n"; 

		if( findParent(CEdges[i].u) != findParent(CEdges[i].v) ){
			egdesadded++;
			parent [ parent[ CEdges[i].u ] ]= parent[ CEdges[i].v];
			cost += CEdges[i].weight;
			totalCost += CEdges[i].weight;

		}
		i++;
	}

	i = 0;

	while(egdesadded <= n-1 && i<m1){
		if( findParent(OEdges[i].u) != findParent(OEdges[i].v) ){
			egdesadded++;
			parent[ parent[ OEdges[i].u ] ]  = parent[ OEdges[i].v];
			totalCost += OEdges[i].weight;

		}
		i++;
	}


	if(egdesadded != n-1)
		printf("Impossible\n");
	else{
		printf("%lld %lld\n",cost,totalCost);
	}

}


int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	
	get(t);
	while(t--){
		solve();
	}
	return 0;
}
