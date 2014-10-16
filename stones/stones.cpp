#include "bits/stdc++.h"
using namespace std;

typedef vector<long int> vi; 
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

lld solve(){
	lld ans;

	return ans;
}

 int main(){
	lld i,j,k,l,n;
	vi a;
	lld t;
	get(t);
	while(t--){
		a.clear();
		get(n);

		rep(n,i) {
			get(k);
			a.pb(k);
		}

		sort(a.rbegin(),a.rend());
		lld ans = 0;
		for(i=0;i<a.size();i = i + 2){
			ans += a[i];
		}	

		cout << ans << endl;
		ans = 0;
	}	
	return 0; 	
 }




