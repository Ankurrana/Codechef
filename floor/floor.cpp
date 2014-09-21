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

lld power4sumupto(lld n){
	double ans = 0;
	ans += (n*n*n)/(double)(3.0) + (n*n*n*n)/(double)2.0 + (n*n*n*n*n)/(double)5.0 - n/(double)30.0;
	return (lld)(ans+0.1);
}



lld power(lld a , lld b,lld MOD){
	long long ans = 1;
	while(b){ 
		if( b&1 ) ans = (ans * a);
		if(ans > MOD) ans %= MOD;
		a = (a * a);
		if(a > MOD) a %= MOD;
		b = b>>1;
	}
	return ans;
}

lld BFsolve(lld n,lld m){
	lld i,j,k,l;
	lld ans = 0;
	for(i=1;i<=n;i++){
		ans = (ans + power(i,4,m)*(lld)(n/i))%m;
		
	}
	return ans;
}



lld solve(lld n,lld m){
	lld i,j,k,l,ans = 0;

	for(i=1;i*i<=n;i++){
		ans = (ans + ((i*i*i*i)*(n/i)))%m;
	}


	lld start = i;
	lld end;
	k = n/(i-1) - 1;

	for(i=k;i>=1;i--){
		end = n/i;
		ans += i*(power4sumupto(end) - power4sumupto(start-1));
		start = end+1;
	}

	return ans;
}



int main(){
	lld i,n,j,k,l;
	lld t;
	get(t);
	while(t--){
		get(n);
		get(m);

		// for(i = 1;i <= 1000000; i++){
		// 	lld e = solve(i);
		// 	lld r = BFsolve(i);
		// 	if( e!= r)
		// 		cout << e << " " << r << endl;
		// }

	}
	
	// cout << ans ;
	return 0; 	
 }




