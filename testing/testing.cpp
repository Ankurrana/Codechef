#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lli;

#define get(a) cin >> a 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,i){ cout << *i << endl; }
#define rep(n,i) for(i=0;i<n;i++)

class C{
public:
	int i;
	C(int l){
		i = l;
	}
	C(){i=0;}
};

class a{
public:
	int i;
	int j;
	C cc;
	a(int _i,int _j,int _c){
		i = _i;
		j = _j;
		cc =  C(_c);
	};
	void setk(int _k){k = _k;};
private:
	int k;

};

int main(){
 	lli i,j,k,l,p,q,x,y;
	pair< int ,int > qwe(2,3); 	
	a obj(2,3,7);
	obj.setk(5);

	k = 0;

	cout << 5/k << endl;
	// C a(2);

	return 0; 	

 }




