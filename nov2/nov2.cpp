#include "bits/stdc++.h"
using namespace std;
 int main(){
	long long int n,m,i,j,l,r,k,p,d;
	vector< int > doihaveananswerforthispos;
	long long int t;
	string str;

	pair<int, int> megamapppershitstuff[9][9] = { make_pair(-1,-1) };

	// A
	megamapppershitstuff[0][1] = make_pair(0,1);
	megamapppershitstuff[0][4] = make_pair(0,4); 
	megamapppershitstuff[0][3] = make_pair(5,8); 
	megamapppershitstuff[0][2] = make_pair(5,7); 

	// B
	megamapppershitstuff[1][0] = make_pair(1,0); 
	megamapppershitstuff[1][2] = make_pair(1,2); 
	megamapppershitstuff[1][3] = make_pair(6,8); 
	megamapppershitstuff[1][4] = make_pair(6,9); 
	
	megamapppershitstuff[2][1] = make_pair(2,1); 
	megamapppershitstuff[2][3] = make_pair(2,3); 
	megamapppershitstuff[2][0] = make_pair(7,5); 
	megamapppershitstuff[2][4] = make_pair(7,9); 
	
	megamapppershitstuff[3][0] = make_pair(8,5); 
	megamapppershitstuff[3][1] = make_pair(8,6); 
	megamapppershitstuff[3][2] = make_pair(3,2); 
	megamapppershitstuff[3][4] = make_pair(3,4); 
	
	megamapppershitstuff[4][0] = make_pair(4,0); 
	megamapppershitstuff[4][3] = make_pair(4,3); 
	megamapppershitstuff[4][1] = make_pair(9,6); 
	megamapppershitstuff[4][2] = make_pair(9,7); 
	

	int theawesomesecondmap[10] = {-1};


	theawesomesecondmap[0] = 5;
	theawesomesecondmap[5] = 0;
	theawesomesecondmap[1] = 6;
	theawesomesecondmap[6] = 1;
	theawesomesecondmap[2] = 7;
	theawesomesecondmap[7] = 2;
	theawesomesecondmap[3] = 8;
	theawesomesecondmap[8] = 3;
	theawesomesecondmap[4] = 9;
	theawesomesecondmap[9] = 4;




	cin >> t;
	while(t--){
		int haveigothteanswer = 0;
		cin >> str;
		doihaveananswerforthispos.resize(str.length());

		for(i=0;i<doihaveananswerforthispos.size();i++) doihaveananswerforthispos[i] = -1;

		for(i=0;i<str.length()-1; i++){
			if( str[i]!=str[i+1] ){
				if(  doihaveananswerforthispos[i]==-1 ){
					doihaveananswerforthispos[i] = megamapppershitstuff[str[i]-'A'][str[i+1]-'A'].first;
					doihaveananswerforthispos[i+1] = megamapppershitstuff[str[i]-'A'][str[i+1]-'A'].second;
					// cout << doihaveananswerforthispos[i] << " " << doihaveananswerforthispos[i+1] << endl;
				}else{
					if( doihaveananswerforthispos[i] != megamapppershitstuff[str[i]-'A'][str[i+1]-'A'].first ){
						haveigothteanswer = true;
						printf("-1\n");
						break;
					}else{
						doihaveananswerforthispos[i+1] = megamapppershitstuff[str[i]-'A'][str[i+1]-'A'].second;
					}
				}
			}else if( str[i]==str[i+1] && doihaveananswerforthispos[i]!=-1 ){
				doihaveananswerforthispos[i+1] = theawesomesecondmap[ doihaveananswerforthispos[i] ];
			}
		}


		for(i=0;i<str.length()-1 && !haveigothteanswer;i++){
			if( str[i]==str[i+1]  ){
				if( doihaveananswerforthispos[i+1]!=-1 ){
					doihaveananswerforthispos[i] = theawesomesecondmap[ doihaveananswerforthispos[i+1] ];
					int j = i-1;
					while( doihaveananswerforthispos[j]==-1 && j>=0 ){ 
						doihaveananswerforthispos[j] = theawesomesecondmap[ doihaveananswerforthispos[j+1]];  
						j--;
					}
				}
			}
		}

		if( !haveigothteanswer && doihaveananswerforthispos[str.length()-1]==-1 ){
			doihaveananswerforthispos[0] = theawesomesecondmap[ str[0]-'A'+5];
			for(int i=1;i<str.length();i++){
				doihaveananswerforthispos[i] = theawesomesecondmap[ doihaveananswerforthispos[i-1] ];
			}
		}

		for(i=0;i<str.length() && !haveigothteanswer;i++){
			printf("%d",doihaveananswerforthispos[i]);
		}

		if(!haveigothteanswer) printf("\n");

	}


	
	return 0; 	
 }














