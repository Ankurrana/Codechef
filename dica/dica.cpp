#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define show(a) tr(a,it){ cout << *it << endl; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)


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

void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}


 int main(){
	lld n,m,i,j,l,r,k,p,d,t;
	lld SevenPowers[50];
	SevenPowers[0] = 1;
	lld Cumulative[50];

	Cumulative[0] = 0;

	for(i=1;i<=22;i++){
		SevenPowers[i] = SevenPowers[i-1] * 7;
		Cumulative[i] = Cumulative[i-1] + SevenPowers[i];
		// cout <<  i  << "  " << SevenPowers[i] << " " << Cumulative[i] << endl;
	}
	

	get(t);


	string str = "dhapusv";
	while(t--){
		get(n);
		n--;
		int chars = upper_bound(Cumulative,Cumulative+22,n) - Cumulative;
		cout << chars <<endl;
		n = n- (Cumulative[chars-1]);
		while(chars > 0 ){
			cout << str[(int)((n)/SevenPowers[chars-1])];
			n = n%SevenPowers[chars-1];
			chars--;
		}
		cout << endl;
	}
	return 0; 	
 }














