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
 	int i,j,k,l,p,q,x,y;
 	int a[10] = {0};	

 	memset(a,0,sizeof(a));

 	for(i=0;i<6;i++){
 		cin >> k;
 		a[k]++;
 	}	

 	int four = 0;
 	int two = 0;
 	int one = 0;

 	for(i=1;i<=9;i++){
 		if(a[i] == 4) 
 			four++;
		if(a[i] == 2) 
			two++;
		if(a[i] == 1) 
			one++;		
 	}	

 	if( four == 1 && two == 1 ){
 		cout << "Elephant" << endl;
 	}else if( four == 1 && one == 2 ){
 		cout << "Bear" << endl;
 	}else{
 		cout << "Alien" << endl;
 	}

	return 0; 	
 }




