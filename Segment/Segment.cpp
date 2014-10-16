#include "bits/stdc++.h"
#include "climits"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
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

vi a;


class Node{
public:
	int twos;
	int threes;
	int fives;
	Node():twos(0),threes(0),fives(0){};
	Node(int a, int b, int c):twos(a),threes(b),fives(c){};
	
	Node operator+(const Node &other) {
		Node a;
		a.twos = twos + other.twos;
		a.threes = threes + other.threes;
		a.fives = fives + other.fives;
		return a;
	}

};

Node Segtree[5000000];

Node buildtree( int Tindex, int l, int r ){
	int mid = (l+r)>>1;
	if( l == r ) {
		if( a[l]%2  == 0) Segtree[Tindex].twos = 1;
		if( a[l]%3  == 0) Segtree[Tindex].threes = 1;
		if( a[l]%5  == 0) Segtree[Tindex].fives = 1;
	
		return Segtree[Tindex];
	}
	else{
		return Segtree[Tindex] = buildtree(2*Tindex+1 , l,mid) + buildtree(2*Tindex + 2,mid+1,r); 
	}

}

int query(int Tindex, int l, int r, int ql, int qr , int p){
	int mid = (l+r) >> 1;
	int ans = 0;

	if( ql <= l && qr >= r ) {
		if(p == 2) return Segtree[Tindex].twos;
		if(p == 3) return Segtree[Tindex].threes;
		if(p == 5) return Segtree[Tindex].fives;
	}

	if(ql <= mid ) ans += query(2*Tindex + 1, l , mid, ql,  min(qr,mid),p );
	if(qr > mid) ans+= query(2*Tindex+2, mid+1,r,max(ql,mid+1),qr,p );
 	
 	return ans;

}



int main(){
  	lld i,j,k,l,n;
	// get(n);
	// Node a1(1,2,3);
	// Node b1(2,3,4);

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);

	buildtree(0,0,5);



	// rep(n,i){
	// 	get(k);
	// 	a.pb(k);
	// }



	return 0; 	
 }




