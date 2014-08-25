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

bool solve(){
	int n,m,i,j,k,l,f,s;
	int a[111111];
	int pos[111111];

	vector< pair< int, int > > Pairs;
	get(n);
	get(m);

	for(i=1;i<=n;i++){
		get(a[i]);
		pos[a[i]] = i;
	}

	rep(m,i){
		get(f); get(s);
		Pairs.push_back(ii(f,s));
		
	}

	sort(all(Pairs));

	int GroupNums[111111];
	for(i=1;i<=n;i++) GroupNums[i] = i;  // Initially all belong to their own group numbers

	for(i=0;i<m;i++){
		int min = Pairs[i].first;
		int max = Pairs[i].second;
		while( GroupNums[max] != GroupNums[min] ) GroupNums[max--] = GroupNums[min];
	}

	// for(i=1;i<=n;i++) cout << i << " "  << GroupNums[i] << endl;

	for(i=1;i<=n;i++){
		if( GroupNums[i] != GroupNums[ a[i] ] ){
			return false;
		}
	}

	return true;
}

 int main(){
	lld i,j,k,l;
	lld t;
	get(t);
	while(t--){
		if(solve()){
			printf("Possible\n");
		}else{
			printf("Impossible\n");
		}
	}	

	return 0; 	
 }





