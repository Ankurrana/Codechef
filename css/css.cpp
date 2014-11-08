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

class attr{
public:
	int p;
	int val;
	void setval(int value, int pri){
		if(pri >= p ){
			p = pri;
			val = value;
		}
	}
	attr(){
		p = 0;
		val = 0;
	}
};

class tag{
public:
	map< int , attr > properties;
	void set(int attrnumber, int value , int prio ){
		properties[attrnumber].setval(value,prio);
	}
	int geto(int attrnumber){
		return properties[attrnumber].val;
	}	
};



int main(){
	lld n,m,i,j,l,r,k,p,q;

	lld a,b,c,d;
	map< int , tag > mymap; 
;

	get(n);
	get(q);

	while(n--){
		get(a);
		get(b);
		get(c);
		get(d);

		mymap[a].set(b,c,d);

	}


	while(q--){
		get(a);
		get(b);
		printf("%d\n",mymap[a].geto(b) );
	}

	return 0;	 	
 }














