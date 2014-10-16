#include "bits/stdc++.h"
using namespace std;

typedef vector<long long int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) i = c.begin();i!= (c).end();i++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,i){ cout << *i << endl; }
#define rep(n,i) for(i=0;i<n;i++)


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


 int main(){
	lld n,m,r,p,i,j,k,l;
	vi a;
	get(n);
	rep(n,i){
		get(k);
		a.pb(k);
	}	


	get(m);

	int q;
	rep(m,q){
		get(k);
		if(k == 1){
			get(l);
			get(r);
			get(p);

			for(i = l-1;i<=r-1;i++){
				if( a[i] % p == 0){
					a[i] /= p;
				}
			}


		}else{
			get(p);
			get(l);
			a[p-1] = l;
		}
	}

	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}

	return 0; 		
 }




