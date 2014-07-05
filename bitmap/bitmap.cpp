#include "bits/stdc++.h"

using namespace std;

#define iterate(n) for(i=0;i<n;i++);
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define lld long long int
#define p(a) printf("%lld\n",(lld)(a));
#define d(a) printf(" (a) : "%lld\n,(lld)a);
#define dv(a,n) iterate(n) { printf("(a)[%d] = %lld\n",(int)i,a[i]) };

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

struct Nodes{
	int i;
	int j;
}N[40000];

void solve(){
	lld i,j,k,n,m;
	string bitmap[200];
	int ans[200][200];
	get(m);
	get(n);
	for(i=0;i<m;i++){
		cin >> bitmap[i];
	};
	lld count = 0;
	Diterate(i,0,m-1){
		Diterate(j,0,n-1){
			if(bitmap[i][j] == '1'){ 
				ans[i][j] = 0;
				N[count].i = i;
				N[count++].j = j;
			}else
				ans[i][j] = 200;
		}
	}

	Diterate(i,0,m-1){
		Diterate(j,0,n-1){
			if(bitmap[i][j] == '0'){  //means black
				int dis = 200;
				Diterate(k,0,count-1){
					dis = abs(N[k].i - i) + abs(N[k].j - j);
					if(dis == 1){
						ans[i][j] = 1;
						break;
					}else{
						ans[i][j] = min( ans[i][j],dis );
					}
				}
			}
		}	
	}

	Diterate(i,0,m-1){
		Diterate(j,0,n-1){
			printf("%d ",ans[i][j] );
		}
		printf("\n");
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

