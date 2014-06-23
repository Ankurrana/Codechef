#include "iostream"
#include "cstdio"
using namespace std;

#define lld long long int
int main(){
	lld t, n, i,j, k,ans1,ans2,ans3;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);

		ans1  = 2 * n*(n-1)*(n-1);
		ans1 = ans1>0?ans1:0L;

		ans2 = n*(n-1)*(n-2);
		ans2 = ans2>0?ans2:0L;

		ans3 = 2*(n)*(n-1)*(n-2)*(n-2);
		ans3 = ans3>0?ans3:0L;

		printf("%lld\n",ans1+ans2+ans3 );

	}
}