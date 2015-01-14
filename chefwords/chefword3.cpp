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

void solve(){
	lld n,k,i,z,j;
	get(n);
	get(k);
	string word;
	vector< string > str; 
	cin >> word;
	
	long double p[26][26];
	long double dp[26][26][100];
	
	rep(26,i){
		rep(26,j){
			cin >> p[i][j];
			dp[i][j][1] = p[i][j];
			// cout << dp[i][j][1] << "\t"; 
		}
		// cout << "\n";
	}
	
	string temp;

	rep(n,i){
		cin >> temp;
		if( temp.length() == word.length() ) str.pb(temp);
	}

	for(int r = 2;r<=k;r++){
		for(i=0;i<26;i++){
			for(j=0;j<26;j++){
				long double temp = 0.000000000000L;
				for(z=0;z<26;z++){
					temp += dp[i][z][r-1]*p[z][j];
				}
				dp[i][j][r] = temp;
				// cout << dp[i][j][r] << "\t";
			}
		}
	}

	long double ans = 0.00000L;
	for(i=0;i<str.size();i++){
		string tempword = str[i];
		long double temp = 1.0000000L; 
		for(j=0;j<tempword.length();j++){
			temp = temp * dp[(word[j]-'a')][ (tempword[j]-'a') ][k];
		}
		ans += temp;
	}

	cout << ans << endl;
}


int main(){
 	int t;
 	cin >> t;
 	while(t--){
 		solve();
 	}
	
	return 0; 	
 }














