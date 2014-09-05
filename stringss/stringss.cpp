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

 int main(){
 	lli n,i,j,k,l,p,q,x,y;
 	string str;

 	cin >> str;

 	tr(str,it){
 		if( isupper(*it) ) *it = tolower(*it);
 		if( *it == 'a' || *it == 'o' || *it == 'y' || *it == 'e' || *it == 'u' || *it == 'i'  ){
				*it = '1'; 			
 		}
 	}

 	tr(str,it){
 		if(*it == '1') continue;
 		else cout << "." << *it ;
 	}

 	printf("\n");
	return 0; 	
 }




