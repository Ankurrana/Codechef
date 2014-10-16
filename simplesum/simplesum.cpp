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

/* This function return the gcd of a and b followed by
    the pair x and y of equation ax + by = gcd(a,b)*/


pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
int modInverse(int a, int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
} 

lld power(lld a , lld b,lld MOD){
	long long ans = 1;
	while(b){ 
		if( b&1 ) 
			ans = (ans * a);
		if(ans > MOD) ans %= MOD;
		a = (a * a);
		if(a > MOD) a %= MOD;
		b >>= 1;
	}
	return ans;
}


int main(){
	lld n,m,i,j,l,r,k,p,d;
	lld t;
	lld x;
	get(t);

	lld ans = 0;
	while(t--){
		get(x);
		get(m);
		get(n);
		if( x == 1){
			ans = (m+1)%n;
		}else{

			n = n * (x-1);
		
			ans = ((power( x,m+1,n) - 1)/(x-1))%n;

		}

		printf("%lld\n",ans%(n/(x-1)) );
	}
	return 0; 	
 }














