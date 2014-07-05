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

#define MOD 1000000007

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

lld power(lld a , lld b,lld mod){
	long long ans = 1;
	while(b){ 
		if( b&1 ) ans = (ans * a);
		if(ans > mod) ans %= mod;
		a = (a * a);
		if(a > mod) a %= mod;
		b = b>>1;
	}
	return ans;
}

class Primer{
private:
	lld primesList[80000] ; //Max upto 10^6
	bool primesBitset[1000001]; // A bitset of primes initially all are primes 
	lld primesCanBeGeneratedUpto;
	lld primesCount;
	void sieve(lld n){  
	 	lld i, j;
		primesBitset[1] = 1; // 1 is not a prime
		for(i=2; i<=n; i++){
			if(primesBitset[i] == 0){
				for(j=i; (i*j)<=n; j++)
					primesBitset[(i*j)] = 1;
				primesList[primesCount++] = i;
			}
		}
	}
public:
	void genPrimesBetween(lld lower , lld higher,lld *resultPrimes){
		if(lower == 1) lower++;
		lld diff = higher - lower + 1;
		bool Bitset[1000001] = {0};
 
		lld sqrthigher = ceil(sqrt(higher));
 
		for(lld i=0;primesList[i] < sqrthigher ;i++){
			lld k = ceil((double)lower/primesList[i]);
			lld maxi = higher/primesList[i];
			if( k == 1 ) k++;
			while(k <= maxi){
				Bitset[k*primesList[i] - lower] = 1;
				k++;
			}
		}
		lld count = 0;
		for(lld i=0;i<higher-lower+1;i++){
			if(Bitset[i]==0)
				resultPrimes[count++] = i + lower;
		}
		resultPrimes[count++] = -1;
 
	}
	Primer(lld n = 10){
		primesCount = 0;
		n = min(n+1,(lld)1e12+1);   
		primesCanBeGeneratedUpto = n;
		sieve(ceil(sqrt(n)));  //Include "cmath"
 
	}
	void printprimes(){
		lld i  = 0;
		for(i=0;i<primesCount;i++){
			cout << primesList[i] << " ";
		}
	}
	
};

lld primes[1300];
int exponent[1300];

void factorise(lld a){
	lld k = a;
	for(int i=0;k>1;i++){
		int count =  0;
		while(k%primes[i] == 0){
			count++;
			k = k/primes[i];
		}
		exponent[i] = max(count,exponent[i]);
	}


}


lld lcm(vector< int > v){
	int i;
	for(i=0;i<1250;i++){ 
		exponent[i] = 0;
	}

	vector< int >::iterator it;
	for(it = v.begin() ; it!=v.end() ; it++){
		factorise(*it);
	}


	// for(int i=0;i<20;i++){
	// 	printf("primes[%d] = %lld raised to the power %d\n",i,primes[i],exponent[i]);		
	// }

	lld ans = 1;

	for(i=0;i<=1230;i++){
		ans = ans * power(primes[i],exponent[i],MOD)%MOD;
	}
	return ans%MOD;

}




int main(){
	
	// Primer pr(10001);
	// pr.genPrimesBetween(1,10000,primes);
	// factorise(36);
	// factorise(8);

	// for(int i=0;i<10;i++){
	// 	printf("primes[%d] = %lld raised to the power %d\n",i,primes[i],exponent[i]);		
	// }


	lld i,j,t,n;
	lld p,q,k,z,l;
	vector < int  > myv;
	vector < int >::iterator it;
	int count , root , next;
	get(t);
	
	Primer pr(10001);
	pr.genPrimesBetween(1,10000,primes);

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


		/* All i need is to find the lcm of all the elements of the vector myv %MOD (but how??)  */ 

		p(lcm(myv));


	}
	return 0;
}


