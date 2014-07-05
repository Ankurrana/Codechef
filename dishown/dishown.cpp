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


struct Chef{
	int lostto;
	int max_score_dish;
}C[10010];


class Dish{
public:
	int score;
	int original_owner;	
	int owner(){
		while(C[original_owner].lostto!=0){
			original_owner = C[original_owner].lostto;
		}
		return original_owner;
	}
}D[10010];





void solve(){
	int i,j,k,n,p,q,s;
	int x,y;
	get(n);
	Diterate(i,1,n){
		get(D[i].score);
		D[i].original_owner = i;
		C[i].lostto = 0;
		C[i].max_score_dish = D[i].score;
	}



	get(q);

	iterate(q){
		get(k);
		if(k==0){
			get(x);
			get(y);
			int xowner = D[x].owner();
			int yowner = D[y].owner();
			if(xowner == yowner ){
				printf("Invalid query!\n");
			}else{

				if(C[xowner].max_score_dish > C[yowner].max_score_dish){
					C[yowner].lostto = xowner;
				}
				else if( C[yowner].max_score_dish > C[xowner].max_score_dish ){
					C[xowner].lostto = yowner;
				}
			}
		}else{
			get(x);
			p(D[x].owner());
		}
	}
}


int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	get(t);
	while(t--){
		solve();
	}
	return 0;
}

