#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define get(a) cin >> a
#define p(a) cout << a
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

int main(){
	ios::sync_with_stdio(false);
	int i,j,t,n;
	int p,q,k,z,l;
	int m;
	get(n);
	get(m);
	int max = 0;
	int index = 1;
	iterate(n){
		get(p);
		z = p/m;
		if(p%m > 0) z++;
		if(z >= max) {
			max = z;	
			index = i + 1;
		}
	}
	p(index);	

	return 0;
}




