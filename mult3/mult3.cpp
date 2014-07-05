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
int T[3000000];

void update(int N,int L,int R,int QL, int QR){
	int LI = N<<1;
	int RI = LI+1;
	int mid = (L + R)>>1;
	if(QL==L && QR==R){ 
		T[N]++;
		T[N] %= 3;
		return;
	}
	if(QL<=mid) update(LI,L,mid,QL,min(QR,mid));
	if(QR>mid)  update(RI,mid+1,R,max(mid+1,QL),QR);
}


int Query(int N,int L, int R, int QL, int QR,int count){
	int LI = N<<1;
	int RI = LI+1;
	int mid = (L + R)>>1;

	if(QL==L && QR==R){
		if( ((T[N] + count) % 3) == 0 )
			return (QR- QL + 1); 
		else
			return 0;
	}
	int sum = 0;
	if(QL<=mid) sum += Query(LI,L,mid,QL,min(QR,mid),count+T[N]);
	if(QR>mid)  sum += Query(RI,mid+1,R,max(mid+1,QL),QR , count + T[N]);

	return sum;

}


int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;
	
	update(1,1,4,1,3);
	update(1,1,4,2,4);

	
	
	dv("T",T,7);

	// get(t);
	// while(t--){
	// }
	return 0;
}

