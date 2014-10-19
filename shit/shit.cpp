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

int steps(char c, int n){
	return (c-'a')/n + (c-'a')%n;
}

 int main(){
	lld n,m,i,j,l,r,k,p,d;
	lld t,q;
	string str;
	get(t);

	while(t--){
		get(n);
		get(q);
		while(q--){
			cin >> str;
			lld ans  = 0;
			int x = 0;
			int y = 0;
			int x1 = 0;
			int y1 = 0;
			for(i=0;i<str.length();i++){
				x1 = (str[i]-'a')/n;
				y1 = (str[i]-'a')%n;
				ans += abs(x1-x) + abs(y-y1);
				x = x1;
				y = y1;
			}
			printf("%lld\n",ans);

		}
	}

	return 0; 	
 }














