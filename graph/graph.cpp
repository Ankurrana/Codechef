#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define print(a) printf("%lld\n",(lld)(a))
#define pb push_back
#define forall(V) for_each(V.begin(),V.end(),func); //Define func for this macro


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

int parentArray[20001];

int parent(int a){
	if( a != parentArray[a] ){
		return parentArray[a] = parent(parentArray[a]);
	}else{
		return parentArray[a];
	}
}

void Union(int a, int b){
	parentArray[ parent(b) ]  = parentArray[a];
}

int main(){
	int i,j,t,n,m;
	int p,q,k,z,l;
	int a, b;
	int ans = true;
	
	get(n);
	get(m);

	if(m != n-1){ 
		printf("NO\n");
		return 0;
	}

	iterate(n+1) 
		parentArray[i] = i;
	

	iterate(m && ans){
		get(a); get(b);
		if( parent(a) == parent(b) ) ans = false;
		else Union(a,b);
	}

	if(ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}

