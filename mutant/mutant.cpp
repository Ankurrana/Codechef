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
	vi a;
	vi::iterator it;
	string str , s;
	get(n);
	cin >> str;
	rep(n,r){
		cin >> s;
		for(i=0;i<str.length();i++){
			if( str[i] == 'z' ) continue;

			int len = s.length();
			int j = i; /* Pointer of the original Sting */
			int k = 0; /* K be the pointer in the second string */


			while( k < s.length()  && j < str.length() ){
				if( str[j] == 'z' ) { 
					j++; 
					continue; 
				};
				if( str[j] == s[k] ) { 
					// cout << str[j];
					k++;
					j++;
				}
				else break;
			}



			if(k==len){
				int k = i;
				while(len > 0){
					if( str[k] != 'z') {
						str[k] = 'z';
						len--;
					}
					k++;
				}
			}


		}
	}

	int count = 0;
	tr(str,it){
		if( *it != 'z') 
			cout << *it;
		else{
			count++;
		}
	}

	if( count == str.length()){
		printf("0\n");
	}
	return 0; 	
 }














