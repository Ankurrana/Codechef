#include "bits/stdc++.h"
#include "climits"
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
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
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

class mypair{
public:
	lld x,y;
	mypair(lld _x, lld _y):x(_x),y(_y){};
	mypair(){};
	bool operator<(mypair other){
		return ((x<other.x) && (y<other.y));
	}	
};

int main(){
	lld t,n,m,i,j,k,l;
	lld p,q;
	vector< mypair > a(1000100);
	vector< mypair > d(1000100, mypair(1e10,1e10));
	vector< mypair >::iterator it;

	get(n);
	rep(n,i){
		get(p); get(q);
		a[i] = mypair(p,q);
	}

	int ans = 0;
	rep(n,i){
		it = lower_bound(all(d),a[i]);
		if(it->x == 1e10 && it->y == 1e10 ) ans++;
		
		*it = a[i];

	}

	printf("%lld\n",ans);

	return 0; 	
 }




