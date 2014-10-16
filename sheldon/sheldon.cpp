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


bool exists(int i, int j){
	if(i >= 0 && j >=0 ){
		if( j < 8 && i <  8)
			return true;
	}
	return false;
}	


int main(){
	lld n,m,i,j,l,r,k,p,d,q;
	vi a;
	vi::iterator it;
	int x,y;
	string mat[8];

	rep(8,i){
		cin >> mat[i];
	}

	bool Protected[8][8] = {true};

	memset(Protected,1,sizeof(Protected));

	




	 k = 8;
	rep(k,i){
		rep(k,j){
			if( mat[i][j] == 'Q' ){
				int r = i,c = j;
				while( exists(r,c) ) { Protected[r--][c] = false;  }
				r = i; c = j;
				while( exists(r,c) ) { Protected[r++][c] = false;  }

				r = i; c = j;
				while( exists(r,c) ) { Protected[r][c--] = false;  }

				r = i; c = j;
				while( exists(r,c) ) { Protected[r][c++] = false;  }


				r = i; c = j;
				while( exists(r,c) ) { Protected[r--][c++] = false;  }

				r = i; c = j;
				while( exists(r,c) ) { Protected[r++][c--] = false;  }


				r = i; c = j;
				while( exists(r,c) ) { Protected[r--][c--] = false;  }

				r = i; c = j;
				while( exists(r,c) ) { Protected[r++][c++] = false;  }
			}
			if( mat[i][j] == 'R'){
				int r,c;
				while( exists(r,c) ) { Protected[r--][c] = false;  }
				r = i; c = j;
				while( exists(r,c) ) { Protected[r++][c] = false;  }

				r = i; c = j;
				while( exists(r,c) ) { Protected[r][c--] = false;  }

				r = i; c = j;
				while( exists(r,c) ) { Protected[r][c++] = false;  }
			}
			if( mat[i][j]== 'B' ){
				int r,c;
				r = i; c = j;
				while( exists(r,c) ) { Protected[r--][c++] = false;  }

				r = i; c = j;
				while( exists(r,c) ) { Protected[r++][c--] = false;  }


				r = i; c = j;
				while( exists(r,c) ) { Protected[r--][c--] = false;  }

				r = i; c = j;
				while( exists(r,c) ) { Protected[r++][c++] = false;  }
			}
			if(mat[i][j] == 'S'){
				int r = i;
				int c = j;
				Protected[r][c] = false;
				Protected[r-1][c] = false;
				Protected[r+1][c] = false;
				Protected[r][c-1] = false;
				Protected[r][c+1] = false;
				Protected[r-1][c-1] = false;
				Protected[r+1][c+1] = false;
				Protected[r-1][c+1] = false;
				Protected[r+1][c-1] = false;
			}
			if(mat[i][j] == 'P'){

				x = i;y = j;
				// cout << x << " " << y << endl;

			}
		}
	}

	bool ans = false; /* She is killed */

	if( Protected[x-1][y] == true ) ans = true;
	if( Protected[x+1][y] == true ) ans = true;
	if( Protected[x][y-1] == true ) ans = true;
	if( Protected[x][y+1] == true ) ans = true;
	if( Protected[x-1][y-1] == true ) ans = true;
	if( Protected[x+1][y+1] == true ) ans = true;
	if( Protected[x-1][y+1] == true ) ans = true;
	if( Protected[x+1][y-1] == true ) ans = true;

	// rep(8,p){
	// 	rep(8,q)
	// 		cout << Protected[p][q];
	// 	cout << endl;
	// }

	if(ans){
		cout << "NOT YET!" << endl;
	}else{
		cout << "CHECKMATE!" << endl;
	}


	return 0; 	
 }














