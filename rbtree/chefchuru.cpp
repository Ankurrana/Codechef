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

void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}

 int main(){
	lld n,m,i,j,l,r,k,p,d,q,x,y;
	vi a;
	vi::iterator it;
	get(n);
	fill(a,n);
	vector< pair<int , int > > f;

	rep(n,i){
		get(x); get(y);
		x--;
		y--;
		f.push_back( make_pair(x,y));
	}
	
	get(q);
	while(q--){
		get(k);
		if(k == 1){
			get(x);
			get(y);
			a[x-1] = y;
			
		}else{
			lld sum = 0;
			get(m);
			get(n);
			m--;
			n--;
			for(i=m;i<=n;i++){
				for(j=f[i].first;j<=f[i].second;j++){
					sum += a[j];
				}
			}
			printf("%lld\n",sum);

		}
	}
	return 0; 	
 }














