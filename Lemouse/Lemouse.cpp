#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
#include <map>
#include <cmath>
 

typedef unsigned long long int lld;
typedef unsigned long int ld;
using namespace std;
 

#define getw getchar_unlocked
#define iterate(n) for(lld i=0;i<n;i++)
#define d_iterate(p,q) for(lld i=p;i<=q;i++)
#define r_iterate(n,z) for(lld i=n-1;i>=n-z;i--) /* z number of elements to the left of n */
#define p(n) printf("%d\n",n);
#define get(n) n = scan2();
#define print_array(k,n) iterate(n){ p(k[i]);}
#define ps(s) printf("%s\n",s);
#define mp make_pair;
#define pb push_back;
#define FOR(i,n) for(int (i)=0;(i)<n;(i)++)
#define D_FOR(i,s,e) for(int (i)=s;(i)<=e;(i)++)


inline int scan2(){
	int n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	return n*s;
}
 


 
int main(){
	int i,z,n,j,k,t,h,ans = 0;
	int b,d,m;
	string str;
	int dp[111][111] = {0};
	int a[111][111] = {0};

	get(n);
	get(m);

	FOR(i,n){
		cin >> str;
		FOR(j,m){
			if( str[j] == '0' )
				a[i+1][j+1] = 0;
			else
				a[i+1][j+1] = 1;
		}

	}

	for(int i=1;i<=m;i++){
		dp[1][i] = dp[1][i-1];
		int count  = 0;
		
		for(int q=-1;q<=1;q++){
			for(int w=-1;w<=1;w++){
				if(a[1+q][i+w] == 1){
					count++;
					a[1+q][i+w] = 0;
				}
			}
		}

		dp[1][i] += count;

	}





	D_FOR(i,2,n){
		D_FOR(j,2,m){
			dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
			int count = 0;

			D_FOR(o,-1,1){
				D_FOR(p,-1,1){
					if( a[i+o][j+p] == 1 ){
						count++;
						a[i+o][j+p] = 0;
					}
				}
			}	

			dp[i][j] += count;

			cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
 
		}
	}


	FOR(i,n+1){
		FOR(j,m+1)
			cout << dp[i][j] << " ";
		ps("");
	}



	cout << dp[n][m];
 
	return 0;
} 

// get(n);
// 	get(m);


// 	iterate(n){
// 		cin >> str;
// 		for(j=0;j<m;j++){
// 			if(str[j] == '0')
// 				a[i+1][j+1] = 0;
// 			else
// 				a[i+1][j+1] = 1;
// 		}
// 	}




// 	FOR(o,n+1){
// 		FOR(p,m+1)
// 			cout << a[o][p] << " " ;
// 		cout << endl;
// 	}



// 	iterate(m){
// 		dp[1][i+1] = dp[1][i];
// 		int count = 0;
// 		for(int k=-1;k<=1;k++){
// 			for(int z=-1;z<=1;z++){
// 					if( a[1+k][i+z] == 1 )
// 						count++;
// 				}
// 		}
// 		dp[1][i+1] += count;

// 	}

// 	iterate(n){
// 		dp[i+1][1] = dp[i][1];
// 		int count = 0;
// 		for(int k=-1;k<=1;k++){
// 			for(int z=-1;z<=1;z++){
// 					if( a[i+k][1+z] == 1 )
// 						count++;
// 				}
// 		}
// 		dp[i+1][1] += count;

// 	}


// 	for(i=2;i<=n;i++){
// 		for(j=2;j<=m;j++){
// 			dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
// 				int count = 0;
// 				for(int k=-1;k<=1;k++){
// 					for(int z=-1;z<=1;z++){
// 						if( a[i+k][j+z] == 1 )
// 							count++;
// 					}
// 				}
// 			dp[i][j] += count;

// 		}
// 	}

	
	
//  	cout << dp[n][m] << endl;