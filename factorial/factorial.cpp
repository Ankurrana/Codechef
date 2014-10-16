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


long long int fact(int a){
	if(a <= 1 ) return 0;
	if(a == 2) return 2;
	if(a > 2) return 6;

	lli ans = 1;
	for(int i=2;i<=a;i++){
		ans *= i;
	}
	return ans;
}


int main(){
 	int i,j,k,l,p,q,x,y,n;
 	cin >> n;
 	int a[2001] = {0};
 	vector< int > arr[2001];


 	rep(n,i){
 		cin >> k;
 		a[k]++;
 		arr[k].pb(i+1);  //this array holds the positions
 	}
 	long long  total = 0;

 	for(i=0;i<2001;i++){
 		// printf("a[%d]  = %d\n", i, a[i]) ;
 		sort( arr[k].begin(),arr[k].end());
 		total += fact(a[i]);
 		if(total >= 3) break;
 	}

 	vector< int >::iterator it;

 	// cout << "total " << total << endl;

 	if(total < 3){
 		cout << "NO" << endl;
 	}else{
 		cout << "YES" << endl;
 		
 		for(k=0;k<=2000;k++){
 			for( it = arr[k].begin();it != arr[k].end();it++ ){
 				cout << *it << " ";
 			}
 		}
 		cout << "\n";
		
		

		int isdone[2001] = false;

		for(k=0;k<=2000;k++){
 			
 			if( next_permutation(arr[k].begin(),arr[k].end()) == false){

 			}
 			
 			for( it = arr[k].begin(); it!=arr[k].end();it++ ){
 				cout << *it << " ";
 			}
 		} 		
 		cout << "\n";
 		flag = true;

 		for(k=0;k<=2000;k++){
 			next_permutation(arr[k].begin(),arr[k].end());
 			for( it = arr[k].begin(); it != arr[k].end();it++ ){
 				cout << *it << " ";
 			}
 		}


 	}

	return 0; 	
 }


// for(int k = 0; k <= 2000;k++){
//  			if(doneyet >= 3){
//  				for(j=0;j<arr[k].size();j++) cout << arr[k][j] << " ";

//  				continue;
//  			} 


//  			if( arr[k].size() > 1 ){
//  				sort( arr[k].begin(),arr[k].end());
			
// 				for(int j = 0; j < arr[k].size() && doneyet < 3;j++){
// 					cout << arr[k][j] << " ";
// 					doneyet++;
// 					next_permutation(arr[k].begin(),arr[k].end());
// 				}
// 			}else if(arr[k].size() == 1){
// 				cout << arr[k][0] << " ";
// 			}
//  		}

