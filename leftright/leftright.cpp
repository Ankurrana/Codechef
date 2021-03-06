#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
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
	lld ans = 1;
	string str;
	cin >> str;

	bool flag = true;
	tr(str,it){
		if(flag){
			if(*it == 'l') ans <<= 1;
			else ans = (ans << 1) + 2;
		}else{
			if( *it == 'l' ) ans = (ans<<1) - 1;
			else ans = (ans << 1) + 1;
		}

		if( ans  >= 1000000007) ans %= 1000000007;
		flag ^= 1;
	}	
	return ans;
}

 int main(){
	lld i,j,k,l;
	vi a;
	lld t;

	// cout << solve();
	get(t);
	while(t--){
		cout << solve() << endl;
	}	
	return 0; 	
 }




