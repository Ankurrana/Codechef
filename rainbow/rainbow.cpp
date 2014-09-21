#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) i = c.begin();i!= (c).end();i++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,i){ cout << *i << endl; }
#define rep(n,i) for(i=0;i<n;i++)


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

long long SmallC(int n, int r, int MOD)
{
	vector< vector<long long> > C(2,vector<long long> (r+1,0));

	for (int i=0; i<=n; i++)
	{
		for (int k=0; k<=r && k<=i; k++)
			if (k==0 || k==i)
				C[i&1][k] = 1;
			else
				C[i&1][k] = (C[(i-1)&1][k-1] + C[(i-1)&1][k])%MOD;
	}
	return C[n&1][r];
}

long long Lucas(int n, int m, int p)
{
	if (n==0 && m==0) return 1;
	int ni = n % p;
	int mi = m % p;
	if (mi>ni) return 0;
	return Lucas(n/p, m/p, p) * SmallC(ni, mi, p);
}

long long C(int n, int r, int MOD)
{
	return Lucas(n, r, MOD);
}




int main(){
	lld i,j,k,l,n;
	lld ans = 0;
	lld mod = 1e9 + 7;
	get(n);
	if(n < 13 ) printf("0\n");
	else{
		n -= 13;
		n = n >>1;
		for(i=0;i<=n;i++){
			ans += C(i+5,5,mod);
			ans = ans%mod;
		}
		cout << ans << endl;
	}

	return 0; 	
 }




