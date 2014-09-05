#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) i = c.begin();i!= (c).end();i++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,i){ cout << *i << endl; }
#define rep(n,i) for(i=0;i<n;i++)


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


bool ispalin(string str){
	int l = str.length();
	int j = l-1;
	int i = 0;
	while(i<j){
		if(str[i++]!=str[j--]) return false;
	}
	return true;
}

 int main(){
	lld i,j,k,l;
	vi a;
	lld t;
	string str;
	get(t);
	while(t--){
		cin >> str;
		if( ispalin(str)) printf("1\n");
		else printf("2\n");
	}	
	return 0; 	
 }




