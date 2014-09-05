#include "bits/stdc++.h"
#include "string"
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

lld solve(){
	int n,v,m,q,i,j,k,l,a,b;
	string str;
	lld ans;
	int mat[1001][1001];
	
	queue< int > myQueue;
	get(n);

	for(i=0;i<n;i++){
		cin >> str;
		for(j=0;j<n;j++){
			mat[i][j] = (str[j]-'0');
		}

	}


	// for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++){
	// 		cout << mat[i][j] << endl;
	// 	}
	// }

	get(q);


	// cout << "Queries = " << q << endl;

	for(i=0;i<q;i++){
		get(v); get(m);
		v--;
		
		for(j=0;j<m;j++){
			get(a); get(b);
			a--;
			b--;
			if( mat[a][b] == 1 ) 
					mat[a][b] = 0;
			else 
				mat[a][b] = 1; 
		}

		
		queue < int > myQueue;
		int distance[1001];
		bool visited[1001];

		memset(distance,0,sizeof(distance));
		memset(visited,false,sizeof(visited));
		
		int source = v;
		myQueue.push(source);
		visited[source] = true;

		while(!myQueue.empty()){
			source = myQueue.front();

			// cout << "Source = " << source << endl;

			for(k=0;k<n;k++){
				if( mat[ source ][k] == 1  ){
					if( visited[k] == false ){
						distance[k] = distance[source] + 1;
						myQueue.push(k);
						visited[k] = true;
					}
				}
			}
		myQueue.pop();
		}

		ans = 0;
		for(int w=0;w<n;w++){
			ans += distance[w];
		}

		printf("%lld\n",ans);
	}
	return 0;

}

 int main(){
	lld i,j,k,l;
	vi a;
	lld t;

	get(t);
	while(t--){
		solve();
	}	
	return 0; 	
 }




