#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) scanf("%d",&a);
#define p(a) printf("%d\n",(lld)(a))
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

int main(){
	int i,j,t,n;
	int p,q,k,z,l;
	int a,b;
	a = 0;
	b = 0;
	iterate(3){
		get(t);
		a += t;
	}

	iterate(3){
		get(t);
		b += t;
	}

	get(n);


	int required = a/5 + b/10;
	if(a%5 > 0) required++;
	if(b%10 > 0) required++;
	if( n >= required)
		printf("YES\n");
	else printf("NO\n");

	return 0;
}

