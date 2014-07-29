#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=1;i<=n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a))
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) Diterate(i,0,n-1) { cout << str << "[" << i << "] = " << a[i] << endl; }

// #define MOD 1000000007

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

struct Node{
	bool isprocessed;
}N[100010];

int shifts[100010];

class LCM{
public:
	int primesList[80001];
	long long MOD;
	int pcount;
	LCM(int maximum = 1000001){
		pcount  = sieve(maximum);
		MOD = 1000000007;
	}

	long long findlcm(vector< int > V){
		int i;
		vector< int >:: iterator it;
		int exponent[80001] = {0};

		for( it=V.begin(); it!=V.end(); it++  ){
			int curr = *it;
			for(i=0;i<pcount && primesList[i]<=curr ;i++){
				int e = 0;
				while(curr > 1 && curr%primesList[i] == 0 ){ e++; curr /= primesList[i]; }
				exponent[i] = max(e,exponent[i] );
			}

		}
		long long ans  = 1;
		for(i=0;i<pcount;i++){
			ans = (ans * power(primesList[i],exponent[i]));
			if(ans > MOD) ans %= MOD;
		}

		return ans;
	}


public:
	long long power(long long a , long long  b){
		long long ans = 1;
		while(b){ 
			if( b&1 ) ans = (ans * a);
			if(ans > MOD) ans %= MOD;
			a = (a * a);
			if(a > MOD) a %= MOD;
			b = b >> 1;
		}
		return ans;
	}
	int sieve(lld n){  
	 	lld i, j,count;
	 	bitset<1000001> primesBitset;
	 	count = 0;
		primesBitset[1] = 1; // 1 is not a prime
		for(i=2; i<=n; i++){
			if(primesBitset[i] == 0){
				for(j=i; (i*j)<=n; j++)
					primesBitset[(i*j)] = 1;
				primesList[count++] = i;
			}
		}

		return count;

	}
	
};




int main(){
	
	lld i,j,t,n;
	lld p,q,k,z,l;
	vector < int  > myv;
	vector < int >::iterator it;
	int count , root , next;
	get(t);
	
	// Primer pr(10001);
	// pr.genPrimesBetween(1,10000,primes);

	while(t--){
		get(n);
		myv.clear();
		iterate(n){
			get(shifts[i]);
			N[i].isprocessed = false;

		}	
		iterate(n){
			if( N[i].isprocessed == false  ){
				N[i].isprocessed = true;
				count  = 1;
				root = i;  
				next = shifts[root];

				while(next!=root){
					N[next].isprocessed = true;
					next = shifts[next];
					count++;	
				}

				myv.push_back(count);
			}

		}

		LCM lcm = LCM(10001);
		/* All i need is to find the lcm of all the elements of the vector myv %MOD (but how??)  */ 

		p( lcm.findlcm(myv) );


	}
	return 0;
}


