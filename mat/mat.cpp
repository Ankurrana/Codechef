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
 

typedef  long long int lld;
typedef  long int ld;
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

 

int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	lld m,p;
	lld row,column;
	// vector< map<lld,lld > > v;
	map< lld,lld > v[100001];
	


	map < lld,lld > mymap;
	map< lld,lld >::reverse_iterator rit;
	
	
	get(n);
	get(m);
	get(p);
 	
 	iterate(p){
 		get(row);
 		get(column);
 		v[row][column]++;
 	}


 	





 	lld current_pos, current_val , last_pos , last_val;



 	for(i=1;i<n+1;i++){
 		ans = 0; 
 		mymap = v[i];
 		mymap[1];
 		mymap[m];
 		rit = mymap.rbegin();

 		last_pos = m;
 		last_val = m + rit->second;
 		
 		++rit;


    	for(;rit!=mymap.rend();++rit){
    		cout << "mymap[" << rit->first << "] = " << rit->second << endl;


    		current_pos = rit->first;
    		current_val = (rit->first) + (rit->second) ;
    		
    		// cout << current_pos << " " << current_val << " " << last_val <<  " " <<last_pos << endl;

    		if( (last_pos - current_pos) == 1 ){
    			if( current_val < last_val  ){
    				ans = -1;
    				break;
    			}
    		}else{
    			if(current_val > current_pos+1 ){
    				ans = -1;
    				break;
    			}
    		}

    		last_val = current_val;
    		last_pos = current_pos;
    	}

    	cout << "ans = " << ans ;

 	}
	




 
	return 0;
} 

