#include "bits/stdc++.h"
#include "string"
using namespace std;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=e ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

bool exists(int n,int m, int i,int j){
	if(i<0 || j<0) return false;
	if(i>=n || j>=m ) return false;
	return true; 
}

int main(){
	ios_base::sync_with_stdio(false);
	int i,j,t;
	int p,q,k,z,l;
	char board[110][111];
	int m,n;
	get(n);
	get(m);

	iterate(n){
		cin >> board[i];
	}


	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(board[i][j] == '.'){
				if(!(i&1) && !(j&1)) board[i][j] = 'B';
				if((i&1) && (j&1)) board[i][j] = 'B'; 
				if(!(i&1) && (j&1)) board[i][j] = 'W'; 
				if((i&1) && !(j&1)) board[i][j] = 'W'; 
			}
		}
	}	


	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout << board[i][j] ;
		}
		cout << "\n";
	}

	return 0;
}




