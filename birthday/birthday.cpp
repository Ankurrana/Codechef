#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


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

// lld uptondigitsnumbers[1000];

// bool sum(lld a){
// 	int ans = 0;
// 	int digits = 0;
// 	while(a){
// 		digits++;
// 		ans = ans + a%10;
// 		a = a/10;
// 		if(ans > 13) return false;
// 	}

// 	if(ans == 13){
// 		return true;
// 	}
// }

// int numdigits(lld a){
// 	int ans = 0;
// 	while(a){
// 		ans++;
// 		a /= 10;
// 	}
// 	return ans;
// }

int main(){
	lld i,j,t,n;
	lld q,k,z,l,ans;
	ios_base::sync_with_stdio(false);
	// lld count = 0;
	// vector<lld> list;
	// vector<lld>::iterator it;
	// for(i=0;i<=100000000;i++){
	// 	if(sum(i)){
	// 		list.push_back(i);
	// 		// p(i);
	// 		count++;
	// 	}
	// }

	// lld dp[750001] = {0};
	// lld c = 1;
	// lld yet = 2;

	// for(it = list.begin();it!=list.end();it++){
	// 	if( numdigits(*it) > yet){
	// 		yet++;
	// 		printf("Incremented at = %lld\n",c );
	// 	}
	// 	dp[c] = yet;
	// 	c++;
	// 	// printf("dp[%lld] = %lld\n",c-1,dp[c-1] );
	// }
	
	// printf("Incremented at = %lld\n",c );

	get(t);
	while(t--){
		get(k);
		if(k<7){
			ans = 2; 
		}else if(k<76){
			ans = 3; 
		}else if(k<481){
			ans = 4; 
		}else if(k <2206){
			ans = 5;
		}else if(k<8233){
			ans = 6;
		}else if(k<26545){
			ans = 7;
		}else if(k<76561){
			ans = 8;
		}

		p(ans);
	}



	return 0;
}

