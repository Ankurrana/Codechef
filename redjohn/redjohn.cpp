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

pair< bitset< 3000001 > , vector< int > > sieve(int n){ 
	int i,j,k,l;
	bitset< 3000001 > isPrime;
	isPrime.set();
	vector< int > primes;
	isPrime[1] = 0;

	for(i=2;i*i<=n;i++){
		if(isPrime[i]) for(j=i*i;j<=n;j = j + i) isPrime[j] = 0;
	}
	for(i=1;i<=n;i++) if(isPrime[i]) primes.push_back(i);

	return make_pair( isPrime,primes );
}

 int main(){
	lld n,m,i,j,l,r,k,p,d,t;
	vi a;
	vi::iterator it;
	vi primes = sieve(3000000).second;

	a.resize(41);
	a[0] = 1 ;
	a[1] = 1 ;
	a[2] = 1 ;
	a[3] = 1 ;

	for(i=4;i<=40;i++){
		a[i] = a[i-1] + a[i-4];
	}

	get(t);
	while(t--){
		get(n);
		cout << upper_bound(primes.begin(),primes.end(),a[n]) - primes.begin() << "\n";
	}


	return 0; 	
 }














