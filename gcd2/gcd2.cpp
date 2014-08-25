#include "bits/stdc++.h"
#include "string"
using namespace std;

int gcd(int a, vector<short int> b){
	int k,i,j,l,q,w;
	int lUsed = 0;
	int lenght = b.size();
	k = 0;
	int key = 0;
	if(lenght <= 6){
		for(i=0;i<lenght;i++) 
			key = key * 10 + b[i];
		return __gcd(a,key);
	}

	while(lUsed < lenght){
		while(k<a && lUsed<lenght) {
			k = k*10 + b[lUsed++];
		}
		k = k%a;
	}

	return __gcd(a,k);
}



int main(){
	int i,j,t,n;
	int p,q,k,z,l,a;
	string str;
	string::iterator it;
	vector<short int > b;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		b.clear();
		cin >> str;

		if(a == 0){ 
			cout << str << endl;
			continue;
		}
		for(it = str.begin(); it!= str.end();it++){
			b.push_back(*it - '0');
		}
		printf("%d\n",gcd(a,b));
	}

	return 0;
}

