#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef unsigned long long int lld;
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


unsigned long long ncr(int n,int r){
	if(r > n ) return 0;
	if( r*2 > n ) r = n-r;
	if( r == 0 ) return 1;

	unsigned long long ans = n;

	for(int i = 2;i <= r ; i++){
		ans *= (n-i+1);
		ans/= i;
	}

	return ans;
}


 int main(){
	lld i,j,k,l;
	lld t;
	get(t);
	while(t--){
		get(k);
		get(l);
		// printf("%lld\n",ncr(k-1,l-1) );

		cout << ncr(k-1,l-1) << endl;
	}	
	return 0; 	
 }




