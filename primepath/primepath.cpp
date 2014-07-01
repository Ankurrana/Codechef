#include "bits/stdc++.h"
#include "string"

using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a))
#define d(str,a) cout << str << ":" << a << endl;
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; };

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
	bool isprime;
	bool isvisited;	
	int distance;
}N[10000];


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

lld primeNodes[10000];	


lld solve(int a, int b){
	int i,j;
	int u;

	iterate(10000){
		N[i].isvisited = false;
	}

	queue < int > q;
	q.push(a);
	N[a].isvisited = true;
	N[a].distance = 0;

	char numb[8];
	char qwe[4];
	int temp;
	int flag = 0;
	while(!q.empty()){
		u = q.front(); q.pop();
		for(i=0;i<4;i++){
			sprintf(numb,"%d",u);  //This function does the conversion
			


			for(j=0;j<=9;j++){
				if(i==0 && j==0) continue;

				numb[i] = j+'0';
				temp = atoi(numb);
				// d("i",i);
				// d("j",j);
				// d("temp",temp);
				if(N[temp].isprime && !N[temp].isvisited && temp!=u){
					q.push(temp);
					N[temp].distance = N[u].distance + 1;
					N[temp].isvisited  = true;
					if(temp == b){
						return N[b].distance ;	
					}
				}

			}
		}

	}	

	return -1;
}

int main(){

	lld i,j,t,n;
	lld p,k,z,l;
	Primer pr(10000);
	pr.genPrimesBetween(1000,9999,primeNodes);
	int count = 0;
	for(i=0;primeNodes[i]!=-1;i++){
		N[primeNodes[i]].isprime = true;
		count++;
	}


	// cout << solve(1033,8179);

	get(t);
	while(t--){
		get(p);
		get(k);
		if(p==k){ 
			p(0);
			continue;
		}		

		int ans = solve(p,k);
		if(ans > 0)
			p(ans);
		else
			printf("Impossible\n");	
	}

	

	return 0;
}

