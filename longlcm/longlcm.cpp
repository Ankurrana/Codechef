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


int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,1003};




 int main(){
	lld i,j,k,l,n,h;
	vi a;
	lld t;
	bool isPrimearray[1000001] = {0};
	bitset< 1000001 > isPrime;


	for(i=0;primes[i] < 1000;i++){
		isPrime[ primes[i] ] = 1;
	}

	int totalPrimes = 168;

	get(t);
	while(t--){
		get(n);
		a.clear();
		rep(n,i){
			get(k);
			a.push_back(k);
		}

		int maxlenght = 1;
		vi primesYet;
		bitset< 1000001 > isOccurred;
		
		isOccurred.reset();

		int lenght = 1;


		for(i=1;i<n;i++){
			if(lenght > maxlenght) maxlenght = lenght;

			if( isPrime[a[i]] ){ 
				if( isOccurred[ a[i] ] == 0 ){
					lenght++;
					if(lenght > maxlenght) maxlenght = lenght;
					primesYet.push_back(a[i]);
					isOccurred[ a[i] ] == 1;

				}else{
						lenght = 1;
						primesYet.clear();
						primesYet.push_back(a[i]);
						isOccurred.reset();
						isOccurred[a[i]] = 1;
				}
					
			}else{
			
					for(h=0;h<primesYet.size() && asd;h++){
						if( a[i]%primesYet[h] == 0  ){
							lenght = 0;
							primesYet.clear();
							isOccurred.reset();
							break;
						}
					}

					
						lenght++;
						if( lenght > maxlenght) maxlenght = lenght;


						for(int h=0;h<168 && primes[h] <= a[i]*a[i] ;h++){
								if( a[i]%primes[h] == 0 ){
									primesYet.push_back(primes[h]);

									isOccurred[ primes[h] ] = 1;
								}
						}
					
			}
		}
		if(maxlenght <= 1){
			printf("-1\n");
		}else
			printf("%d\n",maxlenght );

		

	}	
	return 0; 	
 }




// for(i=1;i<n;i++){
// 			if( isPrime[ a[i] ] && isOccurred[a[i]] == 0  ){
// 				primesYet.push_back(a[i]);
// 				lenght++;
// 				if(lenght > maxlenght) maxlenght = lenght;	
// 			}else{
// 				for(j=0;j<primesYet.size();j++){
// 					if(a[i]%primesYet[j] == 0){
// 						lenght = 1;





// 					}
// 				}


// 			}
// 		}	