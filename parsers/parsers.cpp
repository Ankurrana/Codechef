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
#include <stack>
 

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
 

 

 
lld solve(){
	lld ans = 0;
	string str;
	stack< bool > parser;
	lld i;
	lld flag = 0;

	cin >> str;
	
		ans = 0;

		for(i=0;i<str.length();i++){
			if( parser.size() == 0 ){
				ans = i;
				
			}


			if(str[i] == '<')
				parser.push(1);
			else if( parser.size()!=0 && parser.top() == 1){
				parser.pop();
				if(parser.size() == 0)
					ans = i+1;
			}
			else
				break;

			// cout << parser.size() << " at i = " << i << endl;
			

		}

		
		printf("%lld\n",ans);

}
 
 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	string str;
	get(t);
	lld flag = 0;

	stack< bool > parser;
	while(t--){
		solve();

	}

 
	return 0;
} 

