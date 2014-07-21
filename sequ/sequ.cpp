#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

int main(){
	ios::sync_with_stdio(false);
	int i,j,t,n;
	int p,q,k,z,l;
	int f[10];
	get(f[0]);
	get(f[1]);

	f[2] = f[1] - f[0];

	f[3] = -1 * f[0];
	f[4] = -1 * f[1];
	f[5] = -1 * f[2];


	get(n);
	n--;

	n = n%6;

	if(f[n] < 0) 
		p(1000000007 + f[n])
	else p(f[n]);

	return 0;
}




