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
 

typedef long long int lld;
typedef long int ld;
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


lld solve_row(map < lld,lld  > &mymap , lld m){
	lld last_val, last_pos,current_val,current_pos;
	map< lld ,lld >::reverse_iterator rit;
	lld ans = 0;
	mymap[1];
	mymap[m];

	rit = mymap.rbegin();
	
	last_val = mymap[m] + m;	

	rit++;

	for(;rit!=mymap.rend();rit++){
		// cout << "Values Compares are" <<  " mymap[" << rit->first << "] = " << mymap[rit->first] << endl;
		if( mymap[rit->first]+rit->first > mymap[ (rit->first) + 1]+(rit->first+1) )
			return -1;
		else{
			ans += last_val - ( mymap[rit->first] + rit->first );
			last_val = mymap[rit->first]+rit->first;
		}
	}

	return ans;


}
 
 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	lld m,p;
	lld row,col;
	map< lld ,lld > v[100001];  //an array of maps upto the lenght 100000
	map< lld ,lld >::iterator it;
	map< lld ,lld >::reverse_iterator rit;
	
	get(n); //the number of rows
	get(m); //the number of elements in each row;
	get(p); //the number of times increment is done


	iterate(p){
		get(row);
		get(col);
		v[row][col]++;
	}
	
	/*  These ensure that the input is correctly recieved */

	// d_iterate(1,n){
	// 	map < lld,lld > mymap  = v[i];
	// 	cout << "about row "<< i << endl; 
	// 	for(it=mymap.begin();it!=mymap.end();it++){
	// 		cout << "mymap[" << it->first << "] = " << it->second << endl;
	// 	}
	// }

	lld current_val,current_pos,last_val,last_pos;

	d_iterate(1,n){
		cout << solve_row( v[i],m) << endl;
	}
 
	return 0;
} 
