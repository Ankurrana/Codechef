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

void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}
lld power(lld a , lld b){
	long long ans = 1;
	while(b){ 
		if( b&1 ) ans = (ans * a);
		a = (a * a);
		b >>= 1;
	}
	return ans;
}
 int main(){
	lld n,m,i,j,l,r,k,p,d;
	lld t;
	vi a;
	vi::iterator it;
	get(t);
	while(t--){
		get(n);
		k = n;
		int count = 0;

		while(n > 0){ 
			n /= 10;
			count++;
		}


		if( power(10,count-1) == k )
			cout << "NO" << endl;
		else{
			printf("YES\n");
		}

	}
	return 0; 	
 }














