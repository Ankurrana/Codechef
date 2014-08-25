#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define pb push_back

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

bool isSubsequence(string a, string b){
	string::iterator it1,it2;
	bool ans = false;
	it2 = a.begin();
	it1 = b.begin();


	while( it1 != b.end() && it2 != a.end() ){
		if( *it1 == *it2 ){ 
			it2++ ; 
			it1++ ;
		}
		else it2++;
	}


	if(it1 == b.end()) ans = true;		

	return ans;
}


int sieve(lld n , lld *primesList){  
 	/* @n : The number upto which primes are to be generated */
 	/* @primeList  :  Pointer to a int array where the result is to be stored*/
 	/* returns the number of primes from 2 to n */
 	/* You can also obtain the bitset (for O(1) checking ) by makinbg neccessary changes  */
 	lld i, j , count = 0;
	primesBitset[1000001];
	primesBitset[1] = 1; // 1 is not a prime
	for(i=2; i<=n; i++){
		if(primesBitset[i] == 0){
			for(j=i; (i*j)<=n; j++)
				primesBitset[(i*j)] = 1;
			primesList[primesCount++] = i;
			count++;
		}
	}
	return count;
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
	/*  Define MOD as a PreProcessor or remove from this function if it aint required  */
	long long ans = 1;
	while(b){ 
		if( b&1 ) 
			ans = (ans * a);
		if(ans > MOD)  ans %= MOD;
		a = (a * a);
		if(a > MOD)  a %= MOD;
		b >>= 1;				
	}
	return ans;
}

lld modInverse(lld a , lld m){
	/*  
	 #1 This modMultiplicative method uses Little Fermats theorem for finding Multiplicative Inverse 
		which requires m to be prime ( not just coprime to a ). If m is not prime but co-prime use 
		Eulers Extended algorithm.
	 #2 define MOD equal to m
	*/
	return power(a,m-2,m);
}


int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	string a,b;
	int al, bl;
	bool ans;

	get(t);
	while(t--){
		cin >> a >> b;
		al = a.length();
		bl = b.length();

		if(al > bl){
			ans = isSubsequence(a,b);
		}else {
			ans = isSubsequence(b,a);
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

