#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef unsigned long long int lld;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define show(a) tr(a,it){ cout << *it << endl; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)


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

void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}

 int main(){
	lld n,m,i,j,l,r,p,d;
	long long int k;
	get(n);
	lld a,b;
	bitset<64> a1,b1,c1;
	while(n--){
		get(a);
		get(b);

		if( a== b){
			printf("%lld\n",a);
			continue;
		}
		b++;
		a1 = a;
		b1 = b;		
		k = 63;

		while( k>=0 && (a1[k] == b1[k])){
			c1[k] = a1[k];
			
			k--;
			if(k < 0) break;
		}
		c1[k] = 0;

		k--;


		while(k>=0){
			c1[k] = 1;
			k--;
		}
		d = 0;
		// for(i=0;i<64;i++){
		// 	if( c1[i] )
		// 		d = d + (1<<i);
		// }
		cout << c1.to_ullong() << endl;	
	}


	return 0; 	
 }














