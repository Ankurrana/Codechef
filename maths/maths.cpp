#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=e ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

typedef long long int lli;

int main(){
	lli i,j,t,n;
	lli q,k,z,l;
	
	string a;
	cin >> a;
	
	int p =  a.size();
	k = 0;
	if(p>1)
		k =(int)(a[p-2] - '0');

	k = k*10 + (a[p-1]-'0');

	// cout << k;

	if( k&1 ){
		printf("0");
	}else{
		if( ((k>>1)&1))
			printf("0\n");
		else{
			printf("4\n");
		}
	}


	return 0;
}




