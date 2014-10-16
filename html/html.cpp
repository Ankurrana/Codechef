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
 	ios_base::sync_with_stdio(false);
	lld n,m,i,j,l,r,k,p,d;
	vi a;
	vi::iterator it;
	string str;

	bool isset = false;
	string firstlabel;

	while(  true ){
		std::getline (std::cin,str);

		if( str.length() == 0) break;


		int hashes = 0;
		int attritbutes = 0;
		i = 0;
		while( str[i] == '#' && i < str.length() ) { hashes++;i++;}



		if( str[i] == '<'){
			i++;
			if( str[i] == '/'){
				continue;
			}
			else{
				int len = 0 ;
				int j = i;
				while( str[j] != ' ' && j<str.length() && str[j] != '>' ){ 
					len++;
					j++;
				}
				for(int o = i ;o < len ;o++) cout << str[i];


				while(i < str.length()){
					// cout << str[i] << endl;
					if(str[i++] == '=') attritbutes++;
				}

				// cout << panelname << " " << hashes << " " << attritbutes << "\n" ;
				printf(" %d %d\n",hashes,attritbutes );


			}
		}
	}	



	return 0; 	
 }














