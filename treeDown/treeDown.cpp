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
#define tr(c,i) for(typeof((c).begin()) i = c.begin();i!= (c).end();i++)
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


vi Depth;
vi AL[10001];
int DFrequency[100001];
int maxDepth = 0;

void dfs(int node, int depth){
	Depth[node] = depth;
	DFrequency[depth]++;
	if(depth > maxDepth ) maxDepth = depth;
	
	tr(AL[node],it){
		if( Depth[*it] == 0 ) dfs(*it, depth+1);	
	}

	

}

int solve(){
	int n,i,j,k,l,a,b;
	
	get(n);
	Depth.clear();
	Depth.resize(n+1);

	rep(n+1,i){ 
		DFrequency[i] = 0;
		AL[i].clear();
	}

	for(i=0;i<n-1;i++){
		get(a); get(b);
		AL[a].pb(b);
		AL[b].pb(a); 
	}
	maxDepth = 0;
	dfs(1,1);

	int min = 1;
	int max = maxDepth;
	int ans = 0;
	
	while(min <= max){
		if(DFrequency[min] > 0 ){ 
			ans++;
			DFrequency[min] = 0;
			min++;
		}

		if(DFrequency[max] > 0){
			ans++;
			DFrequency[max]--;

			if( DFrequency[max] == 0 ) max--;
		}

	} 

	return ans;
}

int main(){
	lld i,j,k,l;
	vi a;
	lld t;
	get(t);
	while(t--){
		printf("%d\n",solve());
	}

	// while(t--){

	// }	
	return 0; 	
 }




