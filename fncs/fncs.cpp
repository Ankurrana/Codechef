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
vi a;


class N{
public:
	lld sum;
	N(){ 
		sum = 0;
	};	
	N merge(const N &other){
		N result;
		result.sum = sum + other.sum;
		return result;
	}
};
N SegTree[1000000];

N buildTree(int index, int l, int r){
	int mid = (l+r)>>1;
	if( l == r ) {  
		SegTree[index].sum = a[l];	
	}
	else{
		SegTree[index] = buildTree(2*index+1,l,mid).merge(buildTree(2*index+2,mid+1,r));
	}
	return SegTree[index];
}

void update(int index, int l , int r, int idx ,int p){
	int mid = (l+r)>>1;
	if( l == r ){
		SegTree[index].sum = p;
		return ;
	}

	if( idx <= mid ) { 
		update(2*index+1,l,mid,idx,p);
		
	}else{ 
		update(2*index+2,mid+1,r,idx,p);
	}

	SegTree[index] = SegTree[2*index+1].merge( SegTree[2*index + 2] );
}

vi temp;

void query(int index,int l,int r, int ql, int qr){
	if( ql <= l && r <= qr ){
		// return SegTree[index];
		temp.push_back(index);
		return ;
	}
	int mid = (l+r)>>1;
	N n1, n2;	
	if(ql<=mid) query(2*index+1,l,mid,ql,min(mid,qr));
	if(qr>mid)  query(2*index+2,mid+1,r,max(ql,mid+1),qr);
}

int main(){
	lld n,m,i,j,l,r,k,p,d;
	vi::iterator it;
	vector< vector< int > > f; 
	get(n);
	fill(a,n);


	buildTree(0,0,n-1);

	rep(n,i){
		get(l); get(r);
		temp.clear();
		query(0,0,n-1,l-1,r-1);
		f.push_back(temp);
		// show(f[i]);
	}

	lld x,y;

	lld q;
	get(q);
	while(q--){
		get(k);
		get(x);
		get(y);
		if( k == 1){
			update(0,0,n-1,x-1,y);
		}else{
			lld ans = 0;
			for(int i = x-1 ;i<y; i++  ){
				// cout << "\n IT values : ";
				tr(f[i],it){
					// cout << *it << ",";
					ans += SegTree[*it].sum;
				}
			}
			printf("%lld\n",ans);
		}

	}

	
	return 0; 	
 }














