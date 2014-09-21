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

class Solution{
public:
	lld d;
	lld cR;
	lld a;
	lld pos;
	Solution(lld posi, lld diff, lld e,lld n){
		d = diff;
		a = e - (posi * diff);
		cR = n - 2;
		pos = posi; //the position of the second element in the A.P;
		
		// Two Solution objects can be merged if they are same with some elements changed in between.

	}
};

void solve(){
	lld n,k,i,j,l,p,q,d;
	lld a[1000001];
	get(n); get(p);

	rep(n,i){
		get(a[i]);
	}

	vector< Solution > V;

	lld lastd = a[1] - a[0]; 
	k = 0;

	V.push_back( Solution( 1,lastd,a[1],n+1) );

	for(i=1;i<n;i++){

		d = a[i] - a[i-1];
		if( d == lastd ){
			V[k].cR--;
		}else{
			V.push_back(Solution(i,d,a[i],n));
			k++;
		}
		lastd = d;
	}

	lld min_a = 1e10;
	lld sol_index = 0;

	for(i=0;i<=k;i++){

		// printf("a = %lld d = %lld\n",V[i].a, V[i].d );
		if( V[i].cR <= p && V[i].a <= min_a ){
			if( V[i].a < min_a ){
				sol_index = i;
			}else{
				if( V[i].d  < V[sol_index].d ){
					sol_index = i;
				}
			}
		}
	}



	//Print AP

	for(i=0;i<n;i++){
		printf("%lld ",V[sol_index].a + i*V[sol_index].d );
	}

	printf("\n");

}

 int main(){
	lld i,j,k,l;

	solve();
		
	return 0; 	
 }




