#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lli;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) cin >> a
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define show(a) tr(a,it){ cout << *it << endl; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)
#define print(a) cout << a << "\n"


void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}

 int main(){
 	ios_base::sync_with_stdio(false);
	lli n,m,i,j,l,r,k,p,d;
	int a[21] = {0};
	string str1;
	string str2;	
	double ans = 0.0000000000000000;
	cin >> str1;

	lli finalpos = 0;

	tr(str1,it){
		if(*it == '+' ) finalpos++;
		else finalpos--;
	}

	cin >> str2;
	
	vector< int > reachables[20];

	int hisfixed = 0;
	int questionmarks = 0;

	tr(str2,it){
		if( *it == '+'){
			hisfixed++;
		}else if( *it == '-'){
			hisfixed--;
		}else{
			questionmarks++;
		}
	}


	int minimum = hisfixed - questionmarks;
	int maximum = hisfixed + questionmarks;

	// cout << finalpos << " " << minimum << " " << maximum << " " <<questionmarks << " " << hisfixed <<endl; 
	if( finalpos > maximum || finalpos < minimum ){
			cout << 0.00000000000;
			return 0;
	}

	int temp = 0;

	if( questionmarks == 0){
		if( hisfixed != finalpos ){
			cout << 0.000000000000 << endl;
			return 0;
		}else{
			cout << 1.0000000000000 << endl;
		}
	}else{
		reachables[0].push_back(-1);
		reachables[0].push_back(+1);
		questionmarks--;
		
			for(i=0;i<questionmarks;i++){
				tr(reachables[i],it){
					reachables[i+1].push_back((*it+1));
					reachables[i+1].push_back(*it-1);
				}
			}

			int count = 0;
			tr(reachables[questionmarks],it){
				if( ( hisfixed + *it) == finalpos ) count++;
			}

			cout << setprecision(15) << (double)((double)count/reachables[questionmarks].size());
	}


	

	
	return 0; 	
 }














