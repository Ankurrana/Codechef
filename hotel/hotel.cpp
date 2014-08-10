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

class Customer{
public:
	bool IsSeated;
	vector< int > OrderNumbers; //it stores the position when customer i ordered
	Customer(){
		IsSeated = false;
	}
	int priority(int c){
		if(OrderNumbers.back() < c) 
			return 500;

		vector< int >::iterator it;
		for(it = OrderNumbers.begin();it!=OrderNumbers.end();it++){
			if(*it > c)
				return *it;
		}
	}
}C[401];


int solve(){
	int i,j,k,m,n;
	int Chairs[400] = {0};
	int seatsOccupied = 0;
	int currentOrder;
	int a[401];
	int ans = 0;
	get(n); // the number of seats
	get(m);	//The number of orders

	iterate(401){
		C[i].IsSeated = false;
		C[i].OrderNumbers.clear();
	}


	for(i=1;i<=m;i++){
		get(a[i]);
		C[a[i]].OrderNumbers.push_back(i); 
	}

	currentOrder = 1;

	while(currentOrder <= m && seatsOccupied<n){
		if( C[a[currentOrder]].IsSeated ){
			currentOrder++;
		}else{
			C[a[currentOrder]].IsSeated = true;
			seatsOccupied++;
			Chairs[seatsOccupied] = a[currentOrder];
			ans++;
		}
	}

	// for(i=1;i<=seatsOccupied;i++){
	// 	p(Chairs[i]);
	// }




	while(currentOrder<=m){
		if(C[a[currentOrder]].IsSeated){
			currentOrder++;
		}else{
			int customertoberemoved = Chairs[1];
			int priority = C[Chairs[1]].priority(currentOrder);
			int ChairNumber = 1;
			for(i=1;i<=n;i++){
				if( C[Chairs[i]].priority(currentOrder) > priority  ){
					customertoberemoved = Chairs[i];
					priority = C[Chairs[i]].priority(currentOrder);
					ChairNumber  = i;
				}
			}
			
			C[customertoberemoved].IsSeated = false;
			C[a[currentOrder]].IsSeated = true;
			Chairs[ChairNumber] = a[currentOrder];
			ans++;
		}
	}

	return ans;
}



int main(){
	lld i,j,t,n,m;
	lld p,q,k,z,l;

	get(t);
	while(t--)
		p(solve());
		

	return 0;
}

