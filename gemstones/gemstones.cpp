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
	lld ans = 0,i,j,k,l,p,q,n;
	get(n);
	string str;
	string::iterator it;
	int a[26] = {0};
	bool t[26] = {false};

	rep(n,i){
		
		rep(26,k) {
			t[k] = false;
		}
		cin >> str;
		for(it = str.begin();it!=str.end();it++){
			t[ (*it) - 'a'] = true;
		}

		rep(26,j){
			if(t[j] == true){
				a[j]++;
			}
		}

	}
	rep(26,i){
		// printf("a[%lld] = %d\n",i, a[i]);
		if(a[i] >= n){
			ans++; 
		}
	}

	return ans;
}

 int main(){
	lld i,j,k,l;
	vi a;
	lld t;

	cout << solve();
	// while(t--){
	// 	cout << solve
	// }	
	return 0; 	
 }




