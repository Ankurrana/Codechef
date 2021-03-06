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
};
struct Edge{lld u,v,c;};
struct Node{lld p,sz;};
vector< Node > N;

bool func(Edge a, Edge b){return (a.c < b.c); };

lld parent(lld k){
	return (k==N[k].p)?k:N[k].p = parent(N[k].p);
}

bool cfunc(Edge a, Edge b){
	return a.c > b.c;
}

bool ofunc(Edge a,Edge b){
	return a.c < b.c;
}

void Unite(lld p,lld q){
	lld pp = parent(p);
	lld pq = parent(q);

	if( pp!=pq ){
		if(N[pp].sz > N[pq].sz ){
			N[pq].p = pp;
			N[pp].sz +=  N[pq].sz;
		}else{
			N[pp].p = pq;
			N[pq].sz += N[pp].sz;
		}		
	}

}

void solve(){
	lld n,m1,m2,i,j,k;
	get(n); get(m1); get(m2);
	vector< Edge > C;
	vector< Edge > O;

	C.resize(m2);
	O.resize(m1);
	N.resize(n);
	iterate(n){ N[i].p = i; N[i].sz = 1; };
	iterate(m1){ get(O[i].u); get(O[i].v); get(O[i].c); };
	iterate(m2){ get(C[i].u); get(C[i].v); get(C[i].c); };

	sort(C.begin(),C.end(),cfunc);
	lld EdgesRequired = n - 1;
	lld cost = 0;
	lld totalCost = 0;
	lld cnt = 0;
	for(i=0;i<m2 && EdgesRequired;i++){
		if(parent(C[i].u) != parent(C[i].v) ){
			EdgesRequired--;			
			cost += C[i].c;
			Unite(C[i].u,C[i].v);
		}
	}

	if(EdgesRequired){
		sort(O.begin(),O.end(),ofunc);
		for(i=0;i<m1 && EdgesRequired;i++){
			if(parent(O[i].u) != parent(O[i].v) ){
				// printf("u = %lld v = %lld c = %lld pu = %lld pv = %lld\n",O[i].u,O[i].v,O[i].c,parent(O[i].u),parent(O[i].v) );
				EdgesRequired--;
				totalCost += O[i].c;
				Unite(O[i].u,O[i].v);
			}
		}
	}

	if(EdgesRequired) printf("Impossible\n");
	else printf("%lld %lld\n",cost,cost+totalCost);
}


int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	get(t);
	while(t--)
		solve();
	return 0;
}

