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
	lld n,m,i,j,l,r,k,p,d;
	vi a;
	vi del;
	// vector< set< int >::iterator > del;
	// vector< set< int >::iterator >::iterator dit;

	set< int > mysets[6];
	set< int >::iterator it,sit,eit;
	vi::iterator dit;

	fill(a,6);
	show(a);

	get(n);
	rep(n,i){
		get(k);
		a.pb(k); 
		if( k%2 == 0) mysets[2].insert(i);
		if( k%3 == 0) mysets[3].insert(i);
		if( k%5 == 0) mysets[5].insert(i);
	}

	// for(sit = mysets[2].begin(); sit!= mysets[2].end() ;sit++) cout << *sit << " " ;


	get(m);

	while(m--){

		get(k);
		

		// for(vi::iterator iter =a.begin(); iter!= a.end();iter++) cout << *iter << " " ;
		// cout << endl;

		if(k == 1){
				get(l);
				get(r);
				get(p);
				l--;
				r--;

				sit = lower_bound(mysets[p].begin(),mysets[p].end(),l);


				for(it = sit ; it != mysets[p].end() ; it++) {
					if(*it > r ) break; 
					int index = *it;
					a[index] = a[index]/p;
					
					if( a[index]%p != 0 ){
						del.pb(*it); 
					}
				}

				for(dit = del.begin() ; dit != del.end() ; dit++){
					// cout << "Deleted  =  "  << *dit << endl;
					mysets[p].erase(*dit);
				}

				del.clear();

		}else{
			get(l);
			get(d);
			l--;
			if( a[l]%2 == 0 )  mysets[2].erase(l);
			if( a[l]%3 == 0 )  mysets[3].erase(l);
			if( a[l]%5 == 0 )  mysets[5].erase(l);

			if( d%2 == 0 ) mysets[2].insert(l);
			if( d%3 == 0 ) mysets[3].insert(l);
			if( d%5 == 0 ) mysets[5].insert(l);

			a[l] = d;
		}
	}


	for(vi::iterator it = a.begin();it!=a.end();it++){
		printf("%d ",*it );
	}

	return 0; 	
 }




