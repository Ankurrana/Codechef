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

inline lld scan2(){
	lld n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	return n*s;
}
 


struct array{
	lld a;
	lld b;
} myarray[500010];

struct dpa{
	lld maxa;
	lld maxb;
	lld minab;
} dp[500010];
 

lld min(int i,int k){
	
}
 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	
	get(t);
	
	while(t--){
		get(n);
		get(k);
		lld maxa = 0;
		lld maxb = 0;
		array[0].a = 0;
		array[0].b = 0;
 	
 		dp[0].maxa = 0;
 		dp[0].maxb = 0;
 		dp[0].minb = 0;


		for(i=1;i<=n;i++){
			get(myarray[i].a);
			get(myarray[i].b);
		}

		dp[1].maxa = array[1].a;
 		dp[1].maxb = array[1].b;
 		dp[1].minb = array[1].a * array[1].b;



 		for(i=2;i<=n+1;i++){

 		}


				
	}
 
	
 
}