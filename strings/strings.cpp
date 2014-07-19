#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define get(a) scanf("%d",&a)
#define p(a) printf("%d\n",(int)(a))
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }


int Nsum(int n){
	return (n*(n+1))>>1;

}

int main(){
	int i,j,t,n;
	int p,q,k,z,l;
	string str;
	cin >> str;
	int length = str.length();

	int max = 0;
	int w[29];

	get(k);

	iterate(26){
		get(w[i]);
		if(w[i] > max) max = w[i];		
	}

	int val = 0;
	// str[1] = 'a';
	// cout << str[1];

	// iterate(26) p(w[i]);

	for(i=1;i<=length;i++){
		// p((int)str[i-1] - 'a');
		
		// cout << str[i-1] - 'a';		

		val = val + i * w[  (int)str[i-1] - 'a'  ];
	}

	val += max * (Nsum(k+length) - Nsum(length));

	p(val);
	return 0;
}

