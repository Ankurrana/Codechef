#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) cin >> a
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define show(a) tr(a,it){ cout << *it << endl; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)

vector< pair<int,int> > OtherneighbouringPoints( ii a, ii b ){
	vector< ii > ans;
	int x1,y1,x2,y2;
	x1 = a.first;
	y1 = a.second;
	x2 = b.first;
	y2 = b.second;

	ans.pb( ii(-y1+y2+x2,x1-x2+y2));
	ans.pb( ii(y2-y1+x1,-x2+x1+y1));
	ans.pb( ii(y1-y2+x2,-x1+x2+y2));
	ans.pb( ii(-y2+y1+x1,x2-x1+y1));

	return ans;
}


int main(){
	lld n,m,i,j,l,r,k,p,d;
	lld a, b;
	vi::iterator it;
	vector < pair<  int, int > >  points , others;
	pair<int, int > pointA , pointB;
	get(n);
	rep(n,i){
		get(a);
		get(b);
		points.pb( make_pair(a,b));
	}
	if(n==0) {	printf("4"); return 0; };
	if(n==1) {	printf("3"); return 0; };
	if(n==2) {	printf("2"); return 0; };
	
	sort(points.begin() , points.end());

	int ans = 2;

	for(i=0;i<points.size();i++){
		pointA = points[i];
		for(j=i+1;j<n;j++){
			pointB = points[j];
			others = OtherneighbouringPoints(pointA,pointB);
			bool one = binary_search( points.begin(),points.end(), others[0]);
			bool two = binary_search( points.begin(),points.end(), others[1]);
			bool three = binary_search( points.begin(),points.end(), others[2]);
			bool four = binary_search( points.begin(),points.end(), others[3]);
			
			if( one && two){
				printf("0\n"); return 0;
			}
			if(three && four ){
				printf("0\n"); return 0;
			}
			if( one || two ){
				ans = 1;
			}
			if(three || four ){
				ans = 1;
			}

		}	
	}

	printf("%d\n",ans);

	return 0; 	
 }














