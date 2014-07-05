#include "bits/stdc++.h"

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



int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	lld x,y;
	lld positions[100001];	
	map < lld , int > mymap;
	map < lld , int >::iterator it;

	get(n);
	get(k);
	get(p);

	iterate(n){
		get(positions[i]);  //it denotes the ith frog is sitting on the positions[i]th coordiante
		mymap[positions[i]] = 0;
	}



	it = mymap.begin();


	lld start = it->first;
	lld upto = start + k;
	lld groupNumber = 0;


	for(it = mymap.begin(); it!=mymap.end();it++ ){
		if( (it->first - start) > k )
				groupNumber++;

		it->second = groupNumber;
		start = it->first;
	}

	iterate(p){
		get(x);
		get(y);
		if( mymap[ positions[x-1] ] == mymap[ positions[y-1] ] )
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;	
}

