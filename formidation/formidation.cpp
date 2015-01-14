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
vi primes;

vi prime_factorise( int a ){
	vector< int >::iterator it;
	vector< int > result;

	for(it = primes.begin();it!=primes.end() && a>1 && (*it) * (*it) <= a ; it++  ){
		int count = 0;
		while( a%(*it) == 0 ) (count++, a /= *it);
		result.push_back(count);
	}
	if(a > 1){
		int index = lower_bound(primes.begin(),primes.end(),a) - primes.begin();
		result.resize(index+1);
		result[index] = 1;
	}

	return result;
}

pair< bitset< 1000001 > , vector< int > > sieve(int n){ 
	int i,j,k,l;
	bitset< 1000001 > isPrime;
	isPrime.set();
	vector< int > primes;
	isPrime[1] = 0;
	for(i=2;i*i<=n;i++){
		if(isPrime[i]) for(j=i*i;j<=n;j = j + i) isPrime[j] = 0;
	}
	for(i=1;i<=n;i++) if(isPrime[i]) primes.push_back(i);
	return make_pair( isPrime,primes );
}


vector< lld > CumulativeFactorisation(lld n){
	vector< lld > ans;
	ans.resize(primes.size(),0);
	for(int i=0;i<primes.size() && primes[i]<=n;i++){
		lld k = primes[i];
		while(k <= n ){
			lld t = n/k;
			ans[i] += k*(((t)*(t+1))>>1);
			k = k*primes[i];
		}
	}
	return ans;	
}

lld PowerMod(lld a , lld b,lld MOD){
	long long ans = 1;
	while(b){ 
		if( b&1 ) ans = (ans * a);
		if(ans > MOD) ans %= MOD;
		a = (a * a);
		if(a > MOD) a %= MOD;
		b >>= 1;
	}
	return ans;
}

void TestCase(){
	lld n,m,q,i,j,r;
	get(n);
	get(m);
	get(q);

	vector< lld > nCFactorize = CumulativeFactorisation(n);

	while(q--){
		lld ans = 1;
		get(r);
		vector<lld> aCFactorize = CumulativeFactorisation(n-r);
		vector<lld> bCFactorize = CumulativeFactorisation(r);

		for(i=0;i<primes.size() && primes[i]<=n ;i++){
			lld key = nCFactorize[i] - aCFactorize[i] - bCFactorize[i];
			ans = ans * PowerMod(primes[i],key,m);
			if( ans > m ) ans%= m;
		}
		printf("%lld\n",ans);

	}
}

 int main(){
	lld t;
	vi a;
	vi::iterator it;
	primes = sieve(501).second;
	get(t);
	while(t--){
		TestCase();
	}

	return 0; 	
 }














