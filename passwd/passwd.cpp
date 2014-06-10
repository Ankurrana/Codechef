#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
#include <map>
#include <cmath>
 

typedef unsigned long long int lld;
typedef unsigned long int ld;
using namespace std;
 

#define getw getchar_unlocked
#define iterate(n) for(lld i=0;i<n;i++)
#define d_iterate(p,q) for(lld i=p;i<=q;i++)
#define r_iterate(n,z) for(lld i=n-1;i>=n-z;i--) /* z number of elements to the left of n */
#define p(n) printf("%d\n",n);
#define get(n) n = scan2();
#define print_array(k,n) iterate(n){ p(k[i]);}
#define ps(s) printf("%s\n",s);
#define mp make_pair;
#define pb push_back;
  

inline lld scan2(){
	lld n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	return n*s;
}

 map < char , char > rules;
 
// void reduce(string str){
// 	lld length = str.length();
// 	lld k,i,j,l;

// 	if(length == 1){
// 			printf("%c",str[0]);
// 			return ;
// 	}

// 	for(i=length-1;i>=0;){ 
// 		if(str[i]=='0')
// 			i--;
// 		else
// 			break;
// 	}

// 	k = i;

// 	if(str[k]=='.')
// 		k--;

// 	for(j=0;j<k;){
// 		if(str[j]=='0')
// 			j++;
// 		else
// 			break;
// 	}




// 	for(l=j;l<=k;l++)
// 		printf("%c",str[l]);


// }



void reduce(string str){
	lld i,j,k,l,m,n;
	lld length = str.length();


	//removed all leading zeroes
	for(i=0;i<length-1;){
		if(str[i]=='0')
			i++;
		else
			break;
	}

	lld leftstart = i;
	lld rightend = length - 1;

	for(;i<length;){
		if(str[i]!='.')
			i++;
		else{
			//we have got the dot now we need to remove the trailing zeroes
			for(j=length-1;str[j]=='0';j--)
				rightend--;
				break;
		}
	}




	if(leftstart==rightend && str[leftstart]=='.' ){
			printf("0");
			return;
	}

	if( str[rightend] == '.' )
		rightend--;



	for(i=leftstart;i<=rightend;i++)
			printf("%c",str[i]);



}

int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,d;
	lld r;
	string e_pass ;
	char c;
	char p;
	get(t);
	
	while(t--){
			rules.clear();
			get(r);
			while(r--){
				cin >> c >> p;
				rules[c] = p;
			}
			cin >> e_pass;		
			lld length = e_pass.length();

			iterate(length){
				if( rules.find(e_pass[i]) != rules.end() ){
					e_pass[i] = rules[ e_pass[i] ];
				}
			}

			// cout << e_pass << endl;

			reduce(e_pass);
			ps("");




	}
 
	
 
	return 0;
} 
