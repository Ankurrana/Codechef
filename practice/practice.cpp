#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=e ; i++)
#define get(a) cin >> a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

typedef long long int lli;

class L{
public:
	int p;
	int quality;
	L(int a = 0, int b = 0):p(a),quality(b){};
	bool operator<(L a)const{
		return (this->p) < (a.p);
	}
};
bool ans;
void show(L a){
	cout << "p  = " << a.p << "q = " << a.quality << endl; 
}

int main(){
	int p,q,i,n,z,x;
	vector< L > MyV;
	vector< L >::iterator it;
	
	get(n);
	iterate(n){
		get(p); get(q);
		L t(p,q);
		MyV.push_back(t);
	}

	sort(MyV.begin(),MyV.end());
	bool ans = true;
	for(it = MyV.begin()+1;it!=MyV.end();it++){
		if(!  (it->quality > ((it-1))->quality) ){
			ans = false;
			break;
		}
	}
	if(ans){
		printf("Poor Alex\n");
	}else{
		printf("Happy Alex\n");
	}
}




