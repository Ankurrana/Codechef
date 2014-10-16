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
#define tr(c,it) for(typeof((c).begin()) i = c.begin();i!= (c).end();i++)
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

int sieve(bool *primesBitse){  
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




 int main(){
	lld i,j,k,l;
	vi a;
	lld t;
	get(t);
	while(t--){

	}	
	return 0; 	
 }




