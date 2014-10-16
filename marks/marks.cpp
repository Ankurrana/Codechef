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

class Subjects{
public:
	int totalStudents;
	int a[101] ; /* It will maintain the frequency of students scored i marks in the paticular subject,. if this is more than totalstudents/10 then the answer is unusual */
	Subjects(){ totalStudents = 0;memset(a,0,sizeof(a)); }
	void push(int k){
		a[k]++;
		totalStudents++;
	}

	void printUnusuals(){
		bool nothingUnusual = true;
		for(int i= 0;i<=100;i++){
			if( a[i] > totalStudents/10 && a[i]>0 ){
				printf("%d ",i );
				nothingUnusual = false;
			}
		}

		if(nothingUnusual) printf("Nothing Unusual");
		printf("\n");	
	}
};

int main(){
	lld n,m,i,j,l,r,k,p,d;
	vi a;
	vi::iterator it;
	char c;
	Subjects sub[5];

	get(n);

	rep(n,i){
		cin >> c;
		get(k);
		sub[ c -'A'].push(k);
	}

	rep(5,i){
		sub[i].printUnusuals();
	}
	
	return 0; 	
 }














