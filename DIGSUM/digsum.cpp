#include "iostream"
#include "cstdio"
#include "algorithm"
#include "climits"

#define FOR(i,a,n) for(int i=a;i<n;i++) 
#define PrintArray(a,len) for(int q=0;q<=len;q++) { printf("%d\n",a[q]);  }
using namespace std;





int main(){
	int min_distance[10];
	string str;
	int digits[100010];
	int dis[100010];
	cin >> str;
	int length = str.length();

	FOR(i,0,length) {
		digits[i] = str[i] - '0';   //the digits are converted to int forms	
		dis[i] = i;
	}

	

	FOR(i,0,10)
		min_distance[i] = 100001;

	dis[0] = 0;
	min_distance[ digits[0] ] = 0; 
	dis[length] = INT_MAX - 100;

	for(int j=0;j<10;j++){
		for(int i = 1 ; i<length; i++){
			int mind = INT_MAX;

			mind = min( dis[i-1]+1 , dis[i+1]+1 ) ; //the left and the right
			mind = min( mind , min_distance[digits[i]]+1  );

			if( mind < dis[i] )
				dis[i] = mind;
			if( mind < min_distance[ digits[i] ] ){
				min_distance[ digits[i] ] = mind ; 
			}

			// printf(" digits[%d] = %d \t dis[%d] = %d \t min_distance[ %d ] = %d\n" ,
			//  i,digits[i],i,dis[i],digits[i],min_distance[digits[i]]);


		}
	}

		printf("%d",dis[length-1]);









	// PrintArray(dis,length);

	return 0;

}