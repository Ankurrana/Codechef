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
 
 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d,m;
	lld neven,nodd,meven,modd;
	get(t);

	while(t--){
		get(n);
		get(m);
		
		neven = n>>1;
		meven = m>>1;
		nodd = n>>1;
		modd = m>>1;


		if(n&1) nodd++;
		if(m&1) modd++;

		lld num = nodd*meven + modd*neven;
		lld den = n * m;

		lld a = num , b = den,c;	

		while(b){c = a%b; a = b; b = c;}

		printf("%lld/%lld\n",num/a,den/a);
		

	}
 
	
 
	return 0;
} 

