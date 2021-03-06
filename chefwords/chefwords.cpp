#include "bits/stdc++.h"
#include "string"
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



void solve(){
	lld n,k,i,j,z;
	string str;
	string temp;
	vector< string > strings;
	get(n); get(k);
	cin >> str;
	long double dp[30][30];
	long double p[30][30];
	set< string > myset;
	int numberOfCharacters = 26;
	
	rep(numberOfCharacters,i){
		rep(numberOfCharacters,j){
			cin >> p[i][j];
		}
	}


	int len = str.length();
	rep(n,i){
		cin >> temp;
		if( temp.length() == len && myset.find(temp) == myset.end() ){
			strings.push_back(temp);
			myset.insert(temp);
		}
	}



	double ans[26][26];
	
	rep(26,i){
		rep(26,j){
			if( i==j ) ans[i][i] = 1;
			else ans[i][j] = 0;
		}
	}

	while(k){
		if(k&1){ 
			double temp[26][26];
			
			rep(26,i){
				rep(26,j){
					double qwe = 0.0;
					rep(26,z){
						qwe += ans[i][z]*p[z][j];
					}
					temp[i][j] = qwe;
				}
			}
		
			rep(26,i){
				rep(26,j){
					ans[i][j] = temp[i][j];
				}
			}
		}
		if(1){
			double a[26][26];
			double b[26][26];
			rep(26,i){
				rep(26,j){
					a[i][j] = p[i][j];
					b[i][j] = p[i][j];
				}
			}	
			rep(26,i){
				rep(26,j){
					double qwe = 0.0;
					rep(26,z){
						qwe += a[i][z]*b[z][j];
					}
					p[i][j] = qwe;
				}
			}

		}

		k = k/2;
	}

	
	
	double finalAns = 0.0;
	for(int i=0;i<strings.size();i++){
		temp = strings[i];
		double inter = 1.00000L;
		for(int j=0;j<str.length();j++){
			inter *= ans[ (int)(str[j]-'a') ][ (int)(temp[j]-'a') ] ;
		}
		finalAns += inter;
	}

	cout << finalAns << "\n";
}


 int main(){
	lld n,m,i,j,l,r,k,p,d,t;
		get(t);
		while(t--){
			solve();
		}
	return 0; 	
 }









	// for(int l=2;l<=k;l++){

	// 	for(i=0;i<numberOfCharacters;i++){
	// 		for(j=0;j<numberOfCharacters;j++){
	// 			double ans = 0.0;
	// 			for(z=0;z<numberOfCharacters;z++){					
					
	// 				double temp = ans[i][k][l]*p[k][j]; 
	// 				ans += dp[i][k][l]*p[k][j];

	// 				// if(i==0 && j==0) cout << temp << " for k = " << k << endl ; 

	// 			}
	// 			dp[i][j][l+1] = ans;
	// 		}
	// 	}




