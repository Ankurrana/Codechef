#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;

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

class Interval{
public:
	int s,e;
	Interval(int _a = 0,int _b = 0):s(_a),e(_b){};
	bool operator<(const Interval &other ) const{
		 return s < other.s;
	}
};

vector< Interval > merge(vector< Interval > &a){
	vector< Interval > res;
	for(int i=0;i< a.size();){
		int s = a[i].s;
		int e = a[i].e;
		while(i < a.size() && a[i].s <= e) { 
			e = max(e,a[i].e);
			i++; 
		};
		res.pb(Interval(s,e));
	}
	return res;
}


void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}

 int main(){
	lld n,m,i,j,l,r,k,p,d;
	vi a;
	vector<Interval> intervals , newintervals;
	vi::iterator it;
	get(n); get(k);
	fill(a,n);

	sort(a.begin(),a.end());
	
	rep(k,i){
		get(l);get(r);
		intervals.pb(Interval(l,r));
	}

	sort(intervals.begin(),intervals.end());

	newintervals = merge(intervals);

	lld ans = 0;

	for(int i = 0; i< newintervals.size();i++){
		lld q = (lld)(upper_bound(a.begin(),a.end(),newintervals[i].e) - lower_bound(a.begin(),a.end(),newintervals[i].s));
		ans += q;
		// cout << q << endl;
	}
	cout << ans;
	return 0; 	
 }














