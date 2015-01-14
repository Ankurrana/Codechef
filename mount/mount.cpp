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

vector< long long int> a;

class N{
public:
	int maximum;
	
	N():maximum(-1 * 1e8){ 
	};	
	N merge(const N &other){
		N result;
		result.maximum =  max( maximum,other.maximum);
		return result;
	}
};

N SegTree[2000000];

N buildTree(int index, int l, int r){
	int mid = (l+r)>>1;
	if( l == r ) {  
		SegTree[index].maximum = a[l]; 
	}
	else{
		SegTree[index] = buildTree(2*index+1,l,mid).merge(buildTree(2*index+2,mid+1,r));
	}
	return SegTree[index];
}


/* The updates are of type a, adding p to all elements in the range l to r */


N query(int index,int l,int r, int ql, int qr){
	if( ql <= l && r <= qr )
		return SegTree[index]; 
	int mid = (l+r)>>1;
	N n1, n2;	
	if(ql<=mid) n1 = query(2*index+1,l,mid,ql,min(mid,qr));
	if(qr>mid)  n2 = query(2*index+2,mid+1,r,max(ql,mid+1),qr);
	return  n1.merge(n2);
}

 int main(){
	lld n,m,i,j,l,r,k,p,d;

	vi::iterator it;
	get(n);
	
	for(i=0;i<n;i++){
		get(k);
		a.push_back(k);
	}

	buildTree(0,0,n-1);

	lld q;
	get(q);

	while(q--){
		get(l);
		get(r);
		l--;
		r--;
		lld k = query(0,0,n-1,l+1,r-1).maximum;
		if(k > a[l]){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0; 	
 }














