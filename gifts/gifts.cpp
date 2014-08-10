#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
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
	lld a[52];
	get(t);
	while(t--){
		get(n); get(k);
		for(i=0;i<n;i++){
			get(a[i]);
		}	
		lld count = 0;
		bool flag = false;

		for(i=0;i<n;i++){
			for(j=i;j<n;j++){
				count = 0;
				for(p = i;p<=j;p++){
					if(a[p]%2 == 0)
						count++;
				}
				if(count == k){
					break;
				}
			}
			if(count == k)
				break;
			
		}

		


		if(count == k)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

