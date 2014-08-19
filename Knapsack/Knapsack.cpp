#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define print(a) printf("%lld\n",(lld)(a))
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

int dp[2001][2001];

int main(){
	int i,j,t,n;
	int p,q,k,z,l;
	int size[3000];
	int val[3000];

	int capacity;
	int items;
	get(capacity); get(items);



	for(i=1;i<=items;i++){
		get(size[i]);
		get(val[i]);
		// printf("size[%d] = %d\n",i,size[i] );
		// printf("val[%d] = %d\n",i,size[i] );

	}

	for(int c = 1;c<=capacity;c++){
		for(i=1;i<=items;i++){
			dp[c][i] = dp[c][i-1];
			if( size[i] <= c) 
				dp[c][i] = max(dp[c][i],dp[c-size[i]][i-1] + val[i]);

			// printf("dp[%d][%d] = %d\n",c,i,dp[c][i]);

		}
	}	

	printf("%d",dp[capacity][items]);

	return 0;
}

