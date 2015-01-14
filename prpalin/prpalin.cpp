#include "bits/stdc++.h"
using namespace std;
string str;
bool isthisapalindrome(int , int ,bool );

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> str;
		if( isthisapalindrome(0,str.length()-1,true) ) 
			cout << "YES" << endl;
		else{
			cout << "NO" << endl;
		}

	}	
	return 0; 	
 }

bool isthisapalindrome(int i, int j, bool flag ){
	while(i<=j){
		if( str[i]!=str[j] ){ 
			if( flag ) { 
				return (isthisapalindrome(i,j-1,false) || isthisapalindrome(i+1,j,false));
			}
			else return false;
		}
		i = i + 1;
		j = j - 1;
	}
	return true;
}












