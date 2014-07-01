#include "iostream"
#include "cstdio"

using namespace std;

#define getw getchar_unlocked
#define get(a) geta(&a)

template < typename T >
T gcd(T a, T b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}


template < typename T >
inline void geta(T *a){
	T n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	// return n*s;
	*a = n*s;
}



 
 
int main(){
	long int i,j,k,l,n,t;
	long int min1, min2;
	get(t);
	while(t--){
		// scanf("%ld",&n);
		get(n);
		min1 = 1000001;
		min2 = 1000002;
		for(i=0;i<n;i++){
			// scanf("%ld",&k);
			get(k);
			if(k < min1){
				min2 = min1;
				min1 = k;
			}else if(k<min2){
				min2 = k;
			}
		}
		printf("%ld\n",min1 + min2);
 
	}
} 