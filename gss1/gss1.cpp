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

vector< lld > a;
class Node{
public:	
	lld m;
	Node():m(-1000000000){};
	Node(lld _max):m(_max){};
	Node merge(const Node &other){
		Node result;
		result.m = max( m,other.m );
		return result;
	}
};


Node SegmentTree[3000000];

Node build(int index, int l, int r){
	// cout << l << " " << r << endl;
	if( l==r ) {
		SegmentTree[index].m  =  a[l];
	}else{
		int mid = (l+r)>>1;
		SegmentTree[index] =  build(2*index+1,l,mid).merge( build(2*index+2,mid+1,r));	
	}
	return SegmentTree[index];
}

Node query(int index, int l, int r, int ql, int qr){
	if( l>=ql && r<= qr ){
		return SegmentTree[index];
	}else{
		int mid = (l+r)>>1;
		Node n1,n2;
		if(  ql <= mid ) n1 = query(2*index+1,l,mid,ql,min(qr,mid));
		if(  qr > mid ) n2 = query( 2*index+2,mid+1,r,max(mid+1,ql),qr );
		return n1.merge(n2);
	}
}



int main(){
	lld n,m,i,j,l,r,k,p,d,x,y;
	get(n);
	a.resize(n);
	rep(n,i){
		get(a[i]);
	}

	build(0,0,n-1);

	get(m);
	while(m--){
		get(x);
		get(y);
		cout << query(0,0,n-1,x-1,y-1).m << endl;
	}
	return 0; 	
 }














