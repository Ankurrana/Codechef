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
	bool alluppecase = true;
	bool allcapsafterfirst = true;
	bool capson = false;

	int lenght =  str.lenght();
	rep(lenght,i){
		if( !isupper(str[i]) alluppecase = false; 
	}


	for(i=1;i<str.lenght();i++){
		if(!isupper(str[i])) allcapsafterfirst = false;
	}

	if( alluppecase ){
		capson = true;
	}else{
		if( !alluppecase && allcapsafterfirst){
			capson = false;
		}
	}


	if(capson){
		rep(lenght,i) cout << 
	}

	return 0; 	
 }




