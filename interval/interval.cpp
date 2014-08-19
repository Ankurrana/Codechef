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

class Intervals{
public:
	int s;
	int e;
}I[5001];

bool comp(Intervals a, Intervals b){
	return a.s < b.s;
}


class Q{
	lld p;
	lld k;
	bool ans;
}queries[1001];


bool comp2(Q a, Q b){
	return a.k<b.k;
}

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	ios_base::sync_with_stdio(false);

	get(t);
	while(t--){
		get(n);
		get(q);
		iterate(n){
			get(p); get(q);
			I[i].s = p;
			I[i].e = q;
		}
		sort(I,I+n,comp);
		iterate(q);
		while(q--){
			get(k);
			queries[i].p = i;
			queries[i].k = k; 
			queries[i].ans = false;
		}

		sort(queries,queries+q,comp2);

		int start = 0;
		for(i=0;i<q;i++){		
			for(j=start;j<n;j++){
				if(I[j].s > queries[i].k ) start++;
				
			}
		}



	}



	return 0;
}

