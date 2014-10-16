#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lli;

#define get(a) cin >> a 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,i){ cout << *i << endl; }
#define rep(n,i) for(i=0;i<n;i++)

// qwertyuiop
// asdfghjkl;
// zxcvbnm,./

 int main(){
 	lli i,j,k,l,p,q,x,y;
	string str = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string str2 , str1;
	cin >> str1;
	cin >> str2;

	for(i=0;i<str2.length();i++){
		// cout << str2[i] << endl;
		for(j=0;j<str.length();j++){
			if( str2[i] == str[j] ){
				if( str1[0] == 'L' ) 
					cout << str[j+1];
				else 
					cout << str[j-1];
			}
		}
	}


	return 0; 	
 }




