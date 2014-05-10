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
 
int a[] = {2,3,5,1,4};
int dp[6][6] = {0};




int profit(int year,int s, int e){
	// s {0,n-1} and e too

	if( s == e ){
		dp[s][e] = year*a[e];
		printf("dp[%d][%d] = %d at year = %d\n",s,e,dp[s][e],year);
		return dp[s][e];
	}else if(dp[s][e]!=0 ){
		printf("dp[%d][%d] = %d at year = %d\n",s,e,dp[s][e],year);
		return dp[s][e];
	}else{
		dp[s][e] = max( (profit(year+1,s+1,e)+ year*a[s]),(profit(year+1,s,e-1)+year*a[e]));
		printf("dp[%d][%d] = %d at year = %d\n",s,e,dp[s][e],year);

		return dp[s][e];
	}


}



int main(){
	lld i,z,n,j,k,t,h,ans = 0;

	

	cout << profit(1,0,4);


 
	
 
	return 0;
} 

