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
#define show(a) tr(a,iasdt){ cout << *iasdt << endl; }
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
class solution{
public:
	int row;
	int col;
	int dir;
	solution(int a, int b, int c):row(a),col(b),dir(c){};
	void print(){
		printf("%d %d %d\n",row, col, dir);
	}
};





 int main(){
	lld n,m,i,j,l,r,k,p,d;
	int a,b;
	get(n);
	get(m);
	get(k);

	vector< int > rows[n+1];
	vector< int > cols[m+1];
	vector< solution > SolsA ,  SolsB;

	lld count = 0;



	rep(k,i){
		get(a); get(b);
		rows[a].push_back(b);
		cols[b].push_back(a);
	}

	vi::iterator it;
	// solving by row
	for(i=1;i<=n;i++){
		sort(rows[i].begin(),rows[i].end());
		rows[i].push_back(m+1);

		// cout << " row = " << i << endl;
		// show(rows[i]);

		int start = 1;

		it = rows[i].begin();

		while( it!=rows[i].end() ){
			while(start == *it && it!=rows[i].end() ) ( start++,it++); 
			if( it == rows[i].end() ) break;
			
			SolsA.push_back(solution(i,start,0));
			start = *it;
		}




	}


	for(i=1;i<=m;i++){
		sort(cols[i].begin() , cols[i].end());
		cols[i].push_back(n+1);
		int start = 1;
		it = cols[i].begin();

		// cout << " col = " << i << endl;
		// show(cols[i]);

		


		while( it!=cols[i].end() ){
			while(start==*it && it!= cols[i].end() )( start++,it++ );
			if( it == cols[i].end() ) break;
			SolsB.push_back(solution(start,i,1));
			start = *it;
		}


	}

	if( SolsA.size() < SolsB.size() ){
		printf("%d\n",(int)SolsA.size());
		tr(SolsA,it){
			it->print();
		}
	}else{
		printf("%d\n",(int)SolsB.size());
		tr(SolsB , it){
			it->print();
		}
	}

	return 0; 	
 }














