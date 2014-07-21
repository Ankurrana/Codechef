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
	int i,j,t,n,m;
	int p,q,k,z,l;
	get(n);
	get(m);
	get(k);

	if(n+m-2 < k) 
		p(-1);
	else if(n+m-2 == k){
	 p(1);
	}else {
		if(m>n) swap(n,m);
        if( k <= n-1){
        	p( m * (n/(k+1)) );		  
        }else{
        	int r = k - (n - 1) ;
        	p((m/(r+1)));
        }
	}





	return 0;
}




