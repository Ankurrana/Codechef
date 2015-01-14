#include "bits/stdc++.h"
using namespace std;

typedef long long int lld;

typedef vector<lld> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;

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

void fill(vector<lld> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}

 int main(){
	lld n,m,i,j,l,r,k,p,d;
	vi a;
	vi::iterator it;
	get(n);
	fill(a,n);

	for(i=1;i<n;i++){
		a[i] = a[i-1] + a[i];
	}
	lld sum = a[n-1];
	if(sum%3 != 0){
		printf("0\n");
		return 0;
	}

	k = sum/3;
	lld t = k;
	lld ans = 1;
	lld preCount = 0;
	
	for(i=0;i<n;i++){
		if(a[i] == k){
			preCount++;
		}else if(a[i] > k){	
			ans *= preCount;
			k += t;
			preCount = 0;
			if(a[i] == k) preCount++;
		}
	}

	printf("%lld\n",ans);

	return 0; 	
 }














