#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=d ; i++)
#define getw getchar_unlocked
#define get(a) scanf("%d",&a)
#define p(a) printf("%d\n",(int)(a))
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }



int main(){
	int i,j,t,n;
	int a,p,q,k,z,l;
	int hash[350] = {0};
	get(p);
	get(n);

	iterate(n){
		get(a);
		if(hash[a%p] > 0){
			p(i+1);
			return 0 ;
		}else{
			hash[a%p]++;
		}
	}

	printf("-1\n");
	return 0;
}

