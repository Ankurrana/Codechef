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

 int main(){
	lld n,m,i,j,l,r,k,p,d;
	int a[26] = {0};
	string str;

	cin >> str;

	int len = str.length();

	for(i=0;i<len;){
		char c = str[i];
		int count = 0;
		count = 0;
		while( str[i] == c ){ 
			count++;
			i++;

			// cout << c << endl;
		}
		a[ c - 'a' ] = max( a[c-'a'] , count );

		// cout <<  "for char " << c  << " " << a[c-'a'] << endl;

	}


	int maxleng = a[0];
	char achar = 'a';

	for(i=0;i<26;i++){
		if( a[i] > maxleng ){ 
			maxleng = a[i];
			achar = (char)(i+'a');
		}
	}	

	cout << achar << endl << maxleng << endl;

	return 0; 	
 }














