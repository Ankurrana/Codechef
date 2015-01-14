#include "bits/stdc++.h"
using namespace std;

int myfunction(string str){
	int len = str.length();
	int bal = 0;
	int maxbal = 0;
	for(int i=0;i<len;i++){
		if( str[i]=='(' ) bal++;
		if( str[i] ==')') bal--;
		maxbal = max( maxbal, bal);
	}
	return maxbal;
}

 int main(){
	long long int t,len,k,i;
	string str;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		len = str.length();
		k = myfunction(str);

		for(i=0;i<k;i++) cout << "(";
		for(i=0;i<k;i++) cout << ")";

		cout << endl;
	}
	return 0; 	
 }














