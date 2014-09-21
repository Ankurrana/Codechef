#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef vector<long long int> vi; 
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

int primeCount = 0;
	int primes[1000001];


int sieve(lld n,int *primes){
	bitset<1000001> isprime;
	isprime.set();

	int count = 0,i,j;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j = j + i){
				isprime[j] = 0;
			}
		}
	}
	for(i=2;i<=n;i++){
		if(isprime[i]){
			primes[count++] = i;	
		}
	}

	return count;	
}


lld stringtolong(string str){
	lld ans = 0;
	int len = str.length();
	int i;
	rep(len,i){
		ans  = ans*10 + str[i]-'0';
	}
	return ans;
}


void solve(lld n){
	int i = 0;
	vi ans;
	while(n>1 && primes[i]*primes[i] <= n && i< primeCount){
		while(n%primes[i] == 0){
			ans.pb(primes[i]);
			// ans.pb(n/primes[i]);
			n /= primes[i];
		}
		i++;
	}
	int total = ans.size();
	if( n != 1) total++;
	cout << total << "\n";
	tr(ans,it){
		printf("%lld\n",*it);
	}
	if( n != 1) printf("%lld\n",n);
}

 int main(){
	lld i,j,k,l,n,m,p,q,t;
	primeCount =  sieve(1000000,primes);
	string str;
	get(t);

	while(t--){
		cin >> str;
		int len = str.length();
		if(len <= 11){
			lld n = stringtolong(str);
			solve(n);
		}else{
			cout << 1 << "\n" << str << "\n";  
		}
	}


	return 0; 
}




