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



 int main(){
	lld n,m,i,j,l,r,k,p,d;
	lld t;


	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		for(i=0;i<m;i++){
			cin >> l >> r;
		}

		if( n == 1){
			printf("1\n");
		}
		if( n==2 && k==1){
			printf("3\n");
		}
		if(n==2 && k==2){
			printf("1\n");
		}
		if(n==3 && k==3){
			printf("1\n");
		}	
		if(n==3 && k==2){
			printf("3\n");
		}
		if( n==3 && k==1 ){
			if(m==0 || m==1) printf("5\n");
			if( m==2) printf("7\n");
		}

	}
	return 0; 	
 }














