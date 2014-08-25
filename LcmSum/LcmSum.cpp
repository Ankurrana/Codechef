#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define pb push_back
#define forall(V) for_each(V.begin(),V.end(),func); //Define func for this macro


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



int phi[1000001];
int limit = 1000000;

void ETF(){
	int i,j,k,l;
	phi[1] = 1;
	for(i=2;i<=limit;i++){
		if(phi[i] == 0){
			phi[i] = (i - 1);
			for( j = i*2;j<=limit; j += i ){
				if(phi[j] == 0) phi[j] = j;
				phi[j] = (phi[j]/i)*(i-1);
			}
		}
	}
}

// lld LcmSum(lld a){
// 	lld i,j,k,sqL;
// 	lld ans = 0;
// 	sqL = sqrt(a);
// 	for(i=1;i<=sqL;i++){
// 		if(a%i==0){
// 			ans += phi[i]*i + (phi[a/i] * (a/i));
// 		}
// 	}
// 	ans = ans + 1;
// 	ans = (a * ans)>>1;
// 	return ans;

// 	for(i = 1;i<=limit;i++){

// 	}
// }




int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	lld ans[1000001];

	for(i=1;i<=limit;i++) ans[i] = 2;

	ETF();


	for(i=2;i<=limit;i++){
		lld z = phi[i]*i;
		for(j=i;j<=limit;j+=i){
			ans[j] += z;
		}
	}

	get(t);
	while(t--){
		get(p);
		printf("%lld\n",(p*ans[p])>>1);
	}
	return 0;
}


