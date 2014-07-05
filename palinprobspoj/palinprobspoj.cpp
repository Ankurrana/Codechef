#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
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

int dp[6101][6101];
bool iscalculated[6100][6100] = {0};
string str;

int minpalin(int i,int j){
	// d("i",i);
	// d("j",j);
	if( i>=j ){
		return 0;
	}
	if(iscalculated[i][j]){
		return dp[i][j];
	}else{
		if(str[i] == str[j]){
			 dp[i][j] = minpalin(i+1,j-1);
		}else{
			dp[i][j] = min ( minpalin(i+1,j)+1 , minpalin(i,j-1)+1 );
		 }
		iscalculated[i][j] = true;
		return dp[i][j];
	}
}	



int main(){
	int i,j,t,n;
	int p,q,k,z;
	ios_base::sync_with_stdio (false);
	get(t);
	while(t--){
		cin >> str;
		int l = str.length();

		for(i=0;i<=l;i++){
			for(j=0;j<=l;j++){
				iscalculated[i][j] = 0;
			}
		}


		cout << (minpalin(0,l-1)) << "\n";
	}

	return 0;
}

