#include "iostream"
#include "vector"
#include "cstdio"
#include "algorithm"
using namespace std;

int min(int spaces){
	int mind = 0;
	if(spaces == 0) return 0 ;
	if(spaces == 1) return 0 ;
	if(spaces == 2) return 2 ;
	if(spaces == 3) return 5;
	if(spaces == 4) return 8;  
	if(spaces&1){
		mind = spaces + min(spaces/2) + min(spaces/2 + 1);
	}else{
		mind = spaces + 2*min(spaces/2);
	}
	return mind;
}



int main(){
	int i,j,k;
	int t;
	// vector < vector < int > > allsequences(31); //it denotes all possible sequences possible for the first argument
	// vector < int >::iterator it1;
	// vector < int >::iterator it2;
	
	// allsequences[0].push_back(0);
	// allsequences[1].push_back(2);
	// allsequences[2].push_back(5);
	// allsequences[3].push_back(8);
	// allsequences[3].push_back(9);

	// //Now we need to calculate till 30;



	// vector< int >::iterator it , myit;

	// for(i=4;i<=8;i++){
	// 	for(j=1;j<=(i-i/2);j++){
	// 		for( it=allsequences[i-j].begin() ; it!= allsequences[i-j].end();it++ ){
	// 			for( myit = allsequences[j-1].begin() ; myit!=allsequences[j-1].end();myit++ ){
	// 				// if( allsequencess[i].find( (i+1) + *it + *myit ) == allsequences[i].end() )
	// 					allsequences[i].push_back( (i+1) + *it + *myit ) ;
	// 					cout << (i+1) + *it + *myit << " " ;
	// 			}
	// 		}
	// 	}
	// 	printf("\n");
	//  }

	scanf("%d",&t);
	while(t--){
		int m,n;
		scanf("%d",&n);  //the number of spots
		scanf("%d",&m);  //the lenght of the comm cable
		int max = (((n+1)*(n+2)) / 2) - 1;
		int mind = min(n+1);

		if(m<mind){
			printf("-1\n");
		}else if(m>max){
			printf("%d\n",m-max );
		}else{
			printf("0\n");
		}

	}

	return 0;
} 