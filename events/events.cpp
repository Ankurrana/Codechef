#include "iostream"
#include "cstdio"
#include "algorithm"
#include "vector"
#include "cstdlib"
#define lld long long int
#define get(n) scanf("%d",&n)
#define iterate(n) for(int i=1;i<=n;i++)
#define FOR(i,j,k) for(int i=j;i<=k;i++)

using namespace std;

struct Event{
	int s;
	int e;
	int d;
	int v; //profit
}E[2010];

// vector < struct Event > E(2010);

lld dp[2010][50];




void printdp(int i,int j){
	FOR(k,0,i){
		FOR(l,0,j){
			printf("%lld\t",dp[k][l]);
		}
		printf("\n");
	}
}


int func(const void *a,const void *b){
	Event p = *(Event*)a;
	Event q = *(Event*)b;
	return (p.e > q.e) ;   	
}	



lld solve(){
	int n;
	get(n);
	int t;
	int i;
	int maxt  = 0;
	for(i=1;i<=n;i++){
		get(E[i].s);
		get(E[i].e);
		get(E[i].v);
		E[i].d = E[i].e - E[i].s;
		if(maxt < E[i].e)
			maxt = E[i].e;
	}

	for(i=0;i<=maxt;i++)		
		dp[0][i] = 0;  //means 0 profit is gained if no orders are recieved

	for(i=0;i<=n;i++)
		dp[i][0] = 0;  // means 0 profit is gained until 0 hours of service

	// sort(E.begin()+1 ,E.begin()+n,&func);

	qsort(E,n+1,sizeof(Event),func);

	// for(i=0;i<=n;i++){
	// 	cout << E[i].e << endl;
	// }

	for(t=1;t<=maxt;t++){
		for(i=1;i<=n;i++){
			if( E[i].e <= t ){
				dp[i][t] = max( dp[i-1][E[i].s]+E[i].v , dp[i-1][t]);
				// printf("THIS EXECUTES FOR t = %d and index = %d and E[i].e = %d\n",t,i,E[i].e);
			}else{
				dp[i][t] = dp[i-1][t];
			}

			// printf("%lld\t",dp[i][t]);
		}
		// printf("\n");
	}	


	return dp[n][maxt];

}





int main(){
	int t ;
	get(t);
	while(t--){
		printf("%lld\n",solve());
		// cout << solve() << endl;
	}

	return 0;
}