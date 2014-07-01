#include "iostream"
#include "cstdio"
#include "algorithm"
using namespace std;

int main(){
	int i,j,k,l,t,a,b,x;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&x);
		if(b>a) swap(a,b);

		if(x==0){
			printf("%d\n",0);
			continue;
		}

		if(x>a){
			printf("-1\n");
			continue;
		}
		if(x%b == 0){
			printf("%d\n",(x/b)<<1 );
			continue;
		}
		if((a%b)==(x%b)){

		}


	}
	return 0;
}