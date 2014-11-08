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

bool ischar(char a){
	if( a >= 'A' && a <= 'Z' ) return true;
	return false;
}


bool compare(string  str, int ansi, int ansj, int i, int j){
	int p;
	int q;


	string s1 = str;
	string s2 = str;


	for(p = ansi,q=i;p<=ansj&&q<=j;p++,q++){
		if( ischar(s1[p]) ) s1[p] = '9';
		if( ischar(s2[q]) ) s2[q] = '9';

		if( (int)(s1[p]-'0') > (int)(s2[q]-'0') )
			return false;
 	}

 	return true;
}


int main(){
	lld n,m,i,j,l,r,k,p,d;
	
	vi a;
	vi::iterator it;
	string str;
	cin >> str;



	int len = str.length();

	if(len == 1){
		printf("9\n");
		return 0;
	}


	int charsyet[100001] = {0}; 
	
	if( str[0] >= 'A' && str[0] <= 'Z' ) charsyet[0] = 1;
	else charsyet[0] = 0;


	for(i=1;i<len;i++){
		if( str[i] >= 'A' && str[i] <= 'Z' ){
			charsyet[i] = charsyet[i-1] + 1;
		}else{
			charsyet[i] = charsyet[i-1];
		}
	}

	int maxLenghtyet = 0 ;

	int ansi = 0;
	int ansj = 0;

	for(i=0;i<len;i++){
		for(j=len-1;j>=i;j--){
			while(str[i] == '0') i++;
			if( (j-i+1)>=maxLenghtyet && charsyet[j]-charsyet[i-1] <= 1 ){
				if( (j-(i-1)) > maxLenghtyet ){
					ansi = i;
					ansj = j;
					maxLenghtyet = j-(i-1);
				}else{
					if(!compare(str,ansi,ansj,i,j) ){
						ansi = i;
						ansj = j;
						maxLenghtyet = j-(i-1);
					}
				}	
			}
		}
	}

	i = ansi;
	while(str[i]=='0') i++;
	for(;i<=ansj;i++){ 
		if(ischar(str[i])) printf("9");
		else printf("%c",str[i]);
	}

	return 0; 	
 }














