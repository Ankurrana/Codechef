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
 

typedef long long int lld;
typedef long int ld;
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
	lld b,c,d;
	lld a[1001];
	get(t);
	
	lld diff;
	lld counter = 0;
	while(t--){
		
		counter = 0; //it maintains the current ans count;

		scanf("%lld %lld",&n,&k);


		if( n == 2 ){
			get(c);
			get(d);
			printf("%lld 1\n",abs(c + d - k));
			continue;
		}



		for(i=0;i<n;i++){
			scanf("%lld",a+i);
		}

		ans = abs(a[0] + a[1] - k);
		counter = 0;

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				diff = abs( a[i] + a[j] - k );
				if(diff < ans){
					counter = 1;
					ans = diff;
				}else if( diff == ans ){
					counter++;
				}
				
			}
		}

		printf("%lld %lld\n",ans,counter);

				
	}
 
	
 
	return 0;
} 
