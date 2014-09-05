#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lli;

#define get(a) cin >> a;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,i){ cout << *i << endl; }
#define rep(n,i) for(i=0;i<n;i++)


lli solve(){
	lli ans , n,k,i,j;
	string str;
	cin >> n >> k;
	vi list;
	int fre[26] = {0};
	cin >> str;
	rep(n,i){
		fre[str[i] - 'A']++;
	}

	rep(26,i){
		if( fre[i] > 0 ) list.pb(fre[i]);
	}

	sort(list.rbegin(),list.rend());
	ans = 0;

	tr(list,it){
		if(*it <= k){
			ans = ans + (*it) * (*it);
			k = k - *it;
		}else{
			ans += k*k;
			break;
		}	

	}

	return ans;
}

 int main(){
 lli i,j,k,l,p,q,x,y;

 	cout << solve();
	return 0; 	
 }




