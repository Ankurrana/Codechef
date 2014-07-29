#include "bits/stdc++.h"
#include "string"
using namespace std;
// 00000000000000000
#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define get(a) cin >> a
#define p(a) cout << a
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

typedef long long int lli;

int main(){
	ios::sync_with_stdio(false);
	long long int i,j,t,n,m;
	long long int p,q,k,z,l;
	get(n);
	get(m);
	get(k);
	lli ans = 0;
	if(n+m-2 < k) 
		ans = -1;
	else {
		ans = max((lli)(m/(lli)(k+1))*n,(lli)(n/(k+1))*m);
		if(k>m-1 && k>n-1)
			ans = max(m/(k-n+2),n/(k-m+2));
	}

	cout << ans;



	return 0;
}




