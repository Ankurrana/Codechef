#include "iostream"
#include "cstdio"
#include "cstdlib"
using namespace std;

#define get(n) scanf("%lld",&n)

#define lld long long int

struct TsCs{
	lld Tk;
	lld Ck;
}L[100001];

int func(const void *a,const void * b){
	struct TsCs p = *((TsCs *)a);
	struct TsCs q = *((TsCs *)b);

	return p.Ck > q.Ck;
}

int main(){
	lld h,n,m,totalTk = 0;
	get(n);
	get(m);
	get(h);
	lld tt,tc;

	lld totalBlocks = n*m;

	for(int i=0;i<h;i++){
		get(L[i].Tk);
		get(L[i].Ck);
		totalTk += L[i].Tk;
	}

	if( totalBlocks > totalTk){
		printf("Impossible\n");
		return 0;
	}else{
		qsort(L,h,sizeof(struct TsCs),func);

		lld moreneeded = totalBlocks;
		lld i = 0;
		lld ans  = 0;
		while(moreneeded > L[i].Tk){
			ans += (L[i].Ck)*(L[i].Tk);
			moreneeded -= L[i].Tk;
			i++;
		}	

		ans += moreneeded * L[i].Ck;

		printf("%lld\n",ans);
	}

	return 0;
} 