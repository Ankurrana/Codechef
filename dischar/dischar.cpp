#include "iostream"
#include "cstdio"
using namespace std;

typedef long long int lld;


 int main(){
	lld n,m,i,j,l,r,k,p,d,t;
	string str;
	bool counter[26]; 
	cin >> t;
	while(t--){
		for(i=0;i<26;i++) counter[i] = false;
		int ans = 0;
		cin >> str;
		for(i=0;i<str.length();i++){
			if(!counter[ str[i]-'a' ]){ 
				counter[str[i]-'a'] ^= 1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0; 	
 }














