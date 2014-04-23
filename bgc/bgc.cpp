#include "iostream"
#include "cstdio"
using namespace std;
typedef long long int lld;


#define iterate(n) for(int i = 0;i < (n);i++)

lld dp[1000010] = {0};


lld getmax(lld a){
	if(a<=1000000){
		return dp[a];
	}else{
		return max(a,getmax(a/2)+getmax(a/3)+getmax(a/4));
	}
}



int main(){
	//it required some Dynamic Programming
	//i first need to calculate the answers upto 10^6
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;

	lld b;

	for(lld i = 5;i<=1000000;i++){
		dp[i] = max(i,dp[i/2]+dp[i/3]+dp[i/4]);
	}

	while(cin >> b)
		cout << getmax(b) << endl;


	// iterate(1000){
	// 	cout << getmax(i) << endl; 
	// }

	// cout << getmax(99);
	
	return 0;
}