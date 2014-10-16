#include "bits/stdc++.h"
using namespace std;

typedef vector< int >::iterator vit;

vector< pair<int,int> > OtherneighbouringPoints( pair<int , int> a, pair<int , int> b ){
 vector< pair<int , int> > ans;
 int x1,y1,x2,y2;
 x1 = a.first;
 y1 = a.second;
 x2 = b.first;
 y2 = b.second;

 ans.push_back( pair<int , int>(-y1+y2+x2,x1-x2+y2));
 ans.push_back( pair<int , int>(y2-y1+x1,-x2+x1+y1));
 ans.push_back( pair<int , int>(y1-y2+x2,-x1+x2+y2));
 ans.push_back( pair<int , int>(-y2+y1+x1,x2-x1+y1));

 return ans;
}


int main(){
 long long int n,m,i,j,l,r,k,p,d;
 long long int a, b;
 vector<int>::iterator it;
 vector < pair< int, int > > points , others;
 pair<int, int > pointA , pointB;
 cin >> n;
 for(int (i)=0;(i)<(n);(i)++){
  cin >> a;
  cin >> b;
  points.push_back( make_pair(a,b));
 }
 if(n==0) { printf("4"); return 0; };
 if(n==1) { printf("3"); return 0; };
 if(n==2) { printf("2"); return 0; };

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
