#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
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
	lld p,q,k,z,l,m;
	get(t);
	char gen[] = {'G','A','C','T'};
	while(t--){
		get(n);
		get(m);
		get(k);
		int a;

		int max = 50625;


		if(k<=n*m){
			a = 1;
		}else if(k <= n*m*n && k<=n*m*m){
			a = 1;
		}else if(k <= 2.4*n*m*n || k<=2.4*n*m*m){
			a = 2;
		}
		else if(k <= 0.3*(n*m*n*m)) 
			a = 3;
		else if(k <= n*m*n*m ){
			a = 4;
		}else{
			a = 2;
		}

		Diterate(i,1,n){
			Diterate(j,1,m){
				printf("%c",gen[rand()%a]);
				
			}
			printf("\n");	
		}

	}
	return 0;
}

