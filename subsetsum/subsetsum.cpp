#include "bits/stdc++.h"
#include "string"
using namespace std;



#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define p(a) printf("%lld\n",(lld)(a))
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

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

#define MAXINDEX 10
#define MAX_SUM 100
int dp[100][1000]; // first index then the sum
int a[100];



int main(){
	int n = 4,i,sum,k=0;

	a[0] = 2;
	a[1] = 3;
	a[2] = 7;
	a[3] = 8;

	bool dp[100][1000] = {false};

	iterate(n) dp[i][0] = true;
	dp[0][a[0]] = true;
	iterate(n) k += a[i];

	for(i=1;i<n;i++){
		for(sum = 1;sum <= k;sum++){
			dp[i][sum] = dp[i-1][sum];
			if(sum>=a[i])
				dp[i][sum] = max(dp[i][sum], dp[i-1][sum-a[i]]);
		}
	}

	cout << dp[3][6];

	return 0;
}

