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

bool isSubsetSum(vi set, int n, int sum)
{
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
 
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
 
   
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}
	

int count(vi a, int sum){
	int size = a.size();
	int count = 0;
	for(int i=0;i < (1<<size);i++){
		int temp = 0;
		for(int j=0;j<size;j++)
			if( i&(1<<j) )
				temp += a[j];

		if( temp == sum)
			count++;
		else if( temp > sum)
			return count;

	}
	return count;

}
int main(){
	lld n,m,i,j,l,r,k,p,d;
	lld t;
	get(t);

	vi a;
	vi final;
	map <int , int > mycount;
	map<int, int > v;
	vi wer;

	while(t--){
		get(k);
		final.clear();
		a.clear();
		mycount.clear();
		
		for(i=0;i<1<<k;i++){
			get(u);
			v[u]++;
		}

		v.erase(0);

		tr(v,it){
		 )
		}



	}
	return 0; 	
 }














