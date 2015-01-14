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
	lld n,m,i,j,l,r,k,p,d;
	vector< lld > a;
	vector< lld > cf;
	lld q;
	get(n);
	get(q);

	rep(n,i){
		get(k);
		a.push_back(k);
	}
	for(int i=1;i<n;i++){
		a[i] = a[i-1] + a[i];
	}
	string str;
	lld s;
	rep(q,i){
		cin >> str;
		get(s);
		get(r);
		s--;
		r--;
		if(s==0) printf("%lld\n",a[r]);
		else{
			printf("%lld\n",a[r] - a[s-1]);
		}
	}


	return 0; 	
 }














