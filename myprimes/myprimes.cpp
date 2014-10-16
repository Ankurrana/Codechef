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
	lld ans;
 
	return ans;
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
 
 
int main(){
	lld i,j,k,l,n;
	vi a;
	lld t;
 	vi::iterator it2,it3;
 
 
	get(t);
 
	vi primes = sieve(1000001).second;
	int fre[1000001] = {0};
 
	while(t--){
		int maxi = 0;
		a.clear();
		memset(fre,0,sizeof(fre));
		
		get(n);
		rep(n,i){
			get(k);
			a.pb(k);
		}
 
		int ans = 0;
 
		int pfre[1000001] = {0};
 
		memset(pfre,0,sizeof(pfre));
		
		tr(a,it){
			int k = *it;

			if( k == 1) continue;
			int size = primes.size();

			for(i=0; primes[i]*primes[i] <= k && i<size;i++){
				int count = 0;
				
				while(k%primes[i] == 0) ( count++, k /= primes[i]);
 				
				pfre[i] = max(pfre[i],count);
 				// printf("pre[%lld] = %lld",i,(lld)pfre[i]);


			}
			if( k > 1){
				it2 = lower_bound(primes.begin(),primes.end(),k);
				int index = it2 - primes.begin();
				pfre[index] = max(1, pfre[index]);
			}


		}
 
		for(i=0;i<primes.size();i++){
			ans += pfre[i];
		}
		cout << ans << endl;
 
	}	
 
	return 0; 	
 }
 