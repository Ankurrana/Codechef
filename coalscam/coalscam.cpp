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

inline int findParent(int i){ 
	return (i==parent[i])?i:parent[i] = findParent(parent[i]);
};

int unite(int u, int v){
	parent[findParent(u)] = findParent(v);
}

int isSameSet(int u,int v){
	return (findParent(u) == findParent(v));
}

bool myfunc(struct Edge a, struct Edge b){
	return a.weight < b.weight;
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

	// qsort(OEdges,m1,sizeof(*OEdges),myfunc);
	// qsort(CEdges,m2,sizeof(*CEdges),myfunc);

	sort(OEdges,OEdges+m1,myfunc);
	sort(CEdges,CEdges+m2,myfunc);


	int EdgesRequired = n-1;
	lld cost = 0;
	lld totalCost = 0;
	i = 0;
	while(EdgesRequired && i<m2){
		if( !isSameSet(CEdges[i].v , CEdges[i].u)){
			unite(CEdges[i].v , CEdges[i].u);
			EdgesRequired--;
			cost += CEdges[i].weight;
		}
		i++;
	}


	i = 0;

	while(EdgesRequired && i<m1){
		if( !isSameSet(OEdges[i].u , OEdges[i].v ) ){
			EdgesRequired--;
			totalCost += OEdges[i].weight;
		}
		i++;
	}


	if(EdgesRequired)
		printf("Impossible\n");
	else{
		printf("%lld %lld\n",cost,cost + totalCost);
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


