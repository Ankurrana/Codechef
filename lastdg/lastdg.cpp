#include "bits/stdc++.h"

using namespace std;

#define get(a) scanf("%lld",&(a));
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a));

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	int dig[10][4] = {
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 2,4,8,6 },
		{ 3,9,7,1 },
		{ 4,6,4,6 },
		{ 5,5,5,5 },
		{ 6,6,6,6 },
		{ 7,9,3,1 },
		{8,4,2,6 },
		{9,1,9,1 }
	};


	get(t);
	lld ans = 0;
	while(t--){
		get(p);
		get(q);
		if(q==0) {
			printf("1\n");
			continue;
		}
		p = p%10;
		q = (q-1)%4;
		ans = dig[p][q];

		p(ans);
	}
	return 0;
}

