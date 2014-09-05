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
	lld n,m,i,j,k,l;
	get(n);
	get(m);
	lld sum = 1;

	for(i=2; i*i<=n ;i++){
		if( n%i == 0 ){
			sum += (i + n/i);
			if(sum > m){
				sum = sum%m;
			}
		}
	}
	if( (i * i) == n ) 
		sum -= i;

	sum = (sum+m)%m;

	lld num = sum%m;
	lld numberOfDivisors = 1;
    lld exponent = 1;
    i = 2;
    while (i <= num) {
        if (num%i == 0) {   
            exponent++; 
            num /= i;
        }
        else {
            numberOfDivisors *= exponent;
            exponent = 1;
            i++;
        }
    }
    numberOfDivisors *= exponent; // <-- you were missing this, mainly

	// cout << divisors << endl;

	return --numberOfDivisors;
}

 int main(){
	lld i,j,k,l;
	vi a;
	lld t;
	k = 0;
	l = 1;
	a.pb(k);
	a.pb(l);

	for(i=0;k<1e9;i++){
		a.pb(k+l);
		k = l;
		l = l+k;
	
		// cout << a[i] << endl;
	}




	get(t);
	for(i=1;i<=t;i++){
		 lld k = solve();
		 if( binary_search(all(a),k)){
		 	printf("Case #%lld : YES.\n",i );
		 } else{
		 	printf("Case #%lld : NO.\n",i );
		 }
	}	
	return 0; 	
 }




