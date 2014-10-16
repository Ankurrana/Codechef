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
#define tr(c,it) for(typeof((c).begin()) i = c.begin();i!= (c).end();i++)
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

 int main(){
	lld i,j,k,l,n,q;
	lld t;
	vi a;
	get(n);
	get(q);
	a.resize(n);

	int start = 0;

	rep(n,i){
		get(a[i]);
	}

	char ch;
	rep(q,i){
		scanf("%c",&ch);
		get(k);
		if( ch == 'R'){
			k--;
			printf("%d\n",a[(start+k)%n]);
		}else if( ch == 'A'){
			start = (start + (n-k))%n;
		}else{
			start = (start - (n-k) );
			if( start < 0) 
				start += n;
		}
		// rep(n,j){ 
		// 	cout << a[ (start + j)%n] << "   " ;			
		// }
		// cout << endl;
	}	

	return 0; 	
 }



