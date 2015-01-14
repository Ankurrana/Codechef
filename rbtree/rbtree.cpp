#include "bits/stdc++.h"
using namespace std;

int main(){
	long long n,m,i,j,l,r,k,p,d,q;
	cin >> q;
	string str;
	bool flag = true;
	
	while(q-- > 0){
		cin >> str;
		if( str == "Qi" ){	
			flag ^= 1; 
		}else{
			long long x = 0,y = 0,lefter = 0,righer = 0;
			cin >> x >> y;
			lefter = x;
			righer = y;
			int frequency[20] = {0};
			while( lefter != righer ){
				if( lefter > righer ) { frequency[(((int)log2(lefter)))%2]++; lefter /= 2 ; } 
				else { frequency[((int)log2(righer))%2]++ , righer /= 2; }
			}
			frequency[ (int)log2(lefter)%2 ]++;
			if( str == "Qb" )  cout << frequency[1^flag] << endl;
			else cout << frequency[flag] << endl;

		}
	}

	return 0; 	
 }














