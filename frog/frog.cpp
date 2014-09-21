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



lld power(lld a , lld b){
	long long ans = 1;
	while(b){ 
		if( b&1 ) ans = (ans * a);
		a = (a * a);
		b = b/2;
	}
	return ans;
}

long long findlcm(vector< int > V){
		int i;
		int pcount = 7;
		int primesList[] = {2,3,5,7,11,13,17};
		vector< int >:: iterator it;
		int exponent[10] = {0};

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
		}

		return ans;
	}



 int main(){
	int i,j,k,l,m,n;
	vi a;
	lld t;
	get(t);
	// LCM lcmer;

	while(t--){
		a.clear();
		get(n);
		get(m);

		rep(m,i){
			get(k);
			a.pb(k);	
		}


		cout << n/findlcm(a) << endl;

	}	
	return 0; 	
 }




