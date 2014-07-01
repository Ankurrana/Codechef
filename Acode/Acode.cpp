#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++);
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a));
#define d(a) printf(" (a) : "%lld\n,(lld)a);
#define dv(a,n) iterate(n) { printf("(a)[%d] = %lld\n",(int)i,a[i]) };

template < typename T >
inline void geta(T *a){
	T n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	*a = n*s;
}

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	lld dp[5010];
	string str;
	while(1){
		cin >> str;
		if(str[0] == '0') break;
		dp[0] = 1;
		dp[1] = 1;
		lld length = str.length();
		for(i=2;i<length+1;i++){
			// cout << (int)(str[i-2] - '0')*10 + (str[i-1] - '0') << endl;
			if( (int)(str[i-1]-'0') == 0 ){
				dp[i] = dp[i-2];
			}
			else if( (int)(str[i-2]-'0')*10 + (int)(str[i-1]-'0') <= 26  && (int)(str[i-2]-'0')*10 + (int)(str[i-1]-'0') >= 10)
				dp[i] = dp[i-1] + dp[i-2];
			else
				dp[i] = dp[i-1];
		}
		 p(dp[length]);
	}
	return 0;
}

