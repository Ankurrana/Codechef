#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld unsigned long long int
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

lld root[5500];
class Edge{
public:
	lld u,v;
	lld w;
};

bool func(Edge a, Edge b){
	return a.w < b.w;
}

lld findRoot(lld i){
if( i == root[i])	return i;
else {
	root[i] = findRoot(root[i]);
	return root[i];
}
}
lld Union(lld i, lld j){
	root[findRoot(i)] = findRoot(j);
}

lld isSameSet(lld i, lld j){
	return (findRoot(i) == findRoot(j)) ;
}

void solve(){
	Edge chefs[20500];
	Edge others[20500];
	lld n,m1,m2,p,q,k,i;
	get(n);
	get(m1);
	get(m2);

	for(i=0;i<=n;i++) root[i] = i;
	
	for(i=0;i<m1;i++) {
		get(others[i].u);
		get(others[i].v);
		get(others[i].w);
	}

	for(i=0;i<m2;i++){
		get(chefs[i].u);
		get(chefs[i].v);
		get(chefs[i].w);
	}

	sort(others,others+m1,func);
	sort(chefs,chefs+m2,func);

	lld EdgesRequired = n - 1;
	i = 0;

	lld cost = 0;
	lld others_cost = 0;
	for(i=0;i<m2 && EdgesRequired;i++){
		if( ! isSameSet(chefs[i].u , chefs[i].v )  ){
			Union(chefs[i].u,chefs[i].v );
			EdgesRequired--; 
			cost += chefs[i].w;
		}
	}


	for(i=0;i<m1;i++){
		if( !isSameSet(others[i].u, others[i].v ) ){
			Union(others[i].u , others[i].v);
			EdgesRequired--;
			others_cost += others[i].w;
		}
	}

	if(EdgesRequired)
		printf("Impossible\n");
	else
		printf("%lld %lld\n",cost,others_cost+cost );

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

