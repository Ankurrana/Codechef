#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a))
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

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
		bool primesBitset[1000001]; // 1 is not a prime
	 	
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

 	/* @n : The number upto which primes are to be generated */
	 	/* @primeList  :  Pointer to a int array where the result is to be stored*/
	 	/* returns the number of primes from 2 to n */
	 	/* You can also obtain the bitset (for O(1) checking ) by makinbg neccessary changes  */

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	vector < int > V;
	

	V.push_back(12);
	V.push_back(14);
	V.push_back(6); 
	
	LCM lcm = LCM(14);

	// cout << lcm.power(2,10);

	p(lcm.findlcm(V));

	
	return 0;
}

