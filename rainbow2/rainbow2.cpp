#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector< vi > vvi; 
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

#define M 1000000007

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
lld inverse[10];


lld modpow(int a,int n){	// calc a^n (mod M)
	int r=1;
	for(lld x=a;n;n>>=1,x=(x*x)%M) if(n&1) r=(r*x)%M;
	return r;
}
 
lld inv(int a){	// find x s.t. a*x=1 (mod M) (M:prime)
	return modpow(a,M-2);
}
 
lld modnCr(lld n,lld r){	// calc nCr (mod M) (M:prime)
	if(n<r)		return 0;
	if(n-r<r)	r=n-r;
 	


	lld res=1;
	for(int i=r;i>0;i--){
		res=(res*((n-i+1)%M))%M;
		res=(res*inverse[i])%M;
	}
	return res;
}


lld solve(lld n){
	lld i,j,k,l,ans = 0;
	if( n < 13 ) 
		return 0;
	k = n - 13;
	k = k>>1;
	// Now we have k things to be distributed among 6 items ,  .

	for(i=0;i<=k;i++){
		ans = (ans + modnCr(i+5,5))%M;
	}
	return ans;

}


int main(){
	lld i,j,k,l,n,p,q;
	cin >> n;

	inverse[1] = 1;
	inverse[2] = 500000004;
	inverse[3] = 333333336;
	inverse[4] = 250000002;
	inverse[5] = 400000003;



	cout << solve(n) << endl;
	


	
	return 0; 	
 }




