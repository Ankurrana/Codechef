#include "iostream"
#include "cstdio"
using namespace std;
int main(){
	long long int a,b,c,d,t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		printf("%lf\n",(double)a/(double)(a+b) );
	}
	return 0;
}