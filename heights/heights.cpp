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


 int main(){
	lld n,m,i,j,l,r,k,p,d,t;
	vi a;
	vi::iterator it;
	lld f;
	get(t);
	map< lld, lld > mymap;
	while(t--){
		get(n);
		get(f);
		lld ans = 0;
		mymap.clear();
		lld max = 0;
		rep(n,i){
			get(k);
			mymap[k]++;
			if( k > max) max = k;
		}
		ans = 0;
		tr(mymap,it){
			lld p , q;
			p = it->first;
			q = it->second;
			k = f;
			ans += (q*(q-1))>>1;

			while( (p*k) <= max  ){
				if( mymap.count(p*k) > 0 ) ans+= q*mymap[p*k];
				k = k * f;
				if(k > max) break;
			}

		}

		printf("%lld\n",ans );


	}

	
	return 0; 	
 }












