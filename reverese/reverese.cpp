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

vector< int > AL[100001];
int MinReverses[100001];
vector< int > RAL[100001];
queue< int > Q;
vector< int >::iterator it;



int main(){
	int i,j,t,n,m;
	int p,q,k,z,l;
	int Maximus;

	get(n); get(m);
	
	Maximus = m+1;

	iterate(n+1){
		MinReverses[i] = Maximus; 
	}

	iterate(m){
		get(p); get(q);
		if(p == q) continue;

		AL[p].push_back(q);
		RAL[q].push_back(p);
	}

	Q.push(1);
	MinReverses[1] = 0;

	while(!Q.empty()){
		int p = Q.front(); Q.pop();
		if(MinReverses[p] >= MinReverses[n]) continue;
		for(it = AL[p].begin();it != AL[p].end();it++){
			if(MinReverses[*it] > MinReverses[p]){
				MinReverses[*it] = MinReverses[p];
				// printf("Min[%d] = %d\n",*it,MinReverses[*it] );
				Q.push(*it);
			}
		}

		for(it = RAL[p].begin();it != RAL[p].end();it++){
			if(MinReverses[*it] > MinReverses[p] + 1){
				MinReverses[*it] = MinReverses[p] + 1;
				// printf("Min[%d] = %d\n",*it,MinReverses[*it] );
				Q.push(*it);;
			}
		}
	}

	if(MinReverses[n] == Maximus){
		p(-1);
	}else{
		p(MinReverses[n]);		
	}

	return 0;
}

