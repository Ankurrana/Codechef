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

struct a{
	int a;
	int func(){
		return 0;
	}
};

lld solve(){
	lld ans;

	return ans;
}

 int main(){
	lld i,j,k,l,h,m,n;
	lld t;
	lld height;
	lld a,b,ind;
	lld d[524289];
	int u = 0,y;
	
	get(t);
	while(t--){
		get(height);
		get(n);
		get(m);
		get(a); get(b); get(ind);

		for(i=0;i<m;i++) get(d[i]);

		lld x = 0;

		lld first = ind;

		vi list;
		list.pb(ind);
		for(i=1;i<=n-1;i++) {
			ind = ((a*ind) + b)%m;
			if(ind == first){
				break;
			}
			list.pb(ind);	
		}

		int count = list.size();
		

		int totalsum = 0;

		tr(list,it){
			totalsum += d[*it];
		}

		// cout <<  "Total sum" << totalsum << endl;

		int mynum = (int)((n-1)/count);


		x = x + (mynum*totalsum);

		// cout << "x " << x << endl;

			// cout << "count " << count << endl; 

		int h = (n-1)%count;

		u = 0;

		for(int p=0;p<h;p++){
			x += d[list[p]];
		}


		// cout << (0.5*height*x);
		printf("%.1f\n",(0.5*x*height));



	}	
	return 0; 	
 }




