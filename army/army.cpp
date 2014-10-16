#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) scanf("%lld",&a);
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





int main(){
	lld n,m,i,j,l,r,k,d;
	// vector< Interval > a;
	pair< lld, lld > a[100001]; 

	get(n);
	lld mini , maxi;
	get(mini);
	get(maxi);
	lld x,p;
	rep(n,i){	
		get(x);
		get(p);
		lld s = max(x-p,mini);
		lld e = min(x+p,maxi);

		if( e < mini || s > maxi ) continue;
		// a.push_back(Interval(s,e));
		a[i].first = s;
		a[i].second = e;
	}

	sort(a,a+n);

	lld size = n;
	lld count = 0;

	for(lld i=0;i< size;){
		lld s = a[i].first;
		lld e = a[i].second;
		while(i <size && a[i].first <= e) { 
			e = max(e,a[i].second);
			i++; 
		};
		count += e - s;

		// b.pb(Interval(s,e));
	}

	// for(vector<Interval>:: iterator it = b.begin(); it!=b.end();it++){
	// 	count += (it->e - it->s);
	// }

	printf("%lld\n",(maxi - mini) - count );
	return 0; 	
 }














