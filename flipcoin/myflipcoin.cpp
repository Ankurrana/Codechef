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
 

 struct segTree{
 	bool flag;
 	lld len;
 };

 segTree Tree[1000000];

 void update(int n, int i,int j,int s, int e){
 	if( s>j || e<i || i>j )
 		return ;
 	if( (s==i) && (e==j)){
 		Tree[n].flag ^= 1;
 		Tree[n].len = (j-i+1) - Tree[n].len;
 		return ;
 	}
 	int mid = (i+j) >> 1;

 	if(s>mid){
 		update(2*n+1,mid+1,j,s,e);
 	}else if(e<=mid){
 		update(2*n,i,mid,s,e);
 	}
 	else{
 		update(2*n,i,mid,s,mid);
 		update(2*n+1,mid+1,j,mid+1,e);
 	}
 	Tree[n].len = Tree[2*n].len + Tree[2*n+1].len;  
 	// We need not care about the actual val now as we can get the correct val from its childs
 	//But in case the node is updated odd number of times , 
 	//we need to do the exchanging again to maintain the incorrect val
 	
 	if(Tree[n].flag) 
 		Tree[n].len = (j-i+1) - Tree[n].len;

 }


 lld query(int n,int i,int j,int s,int e, bool flag){

 	// printf("#i = %d ,#j = %d ,#s = %d #e = %d\n",i,j,s,e);


 	if(s>j || e<i || i>j){
 		return 0;
 	}
 	if( (s==i) && (e==j) ){
 		if(flag)
 			return (j-i + 1) - Tree[n].len;
 		else
 			return Tree[n].len;
 	}
 	 flag = flag ^ Tree[n].flag;
 	 int mid  = (i+j)>>1;
 	 if( s>mid )
 	 	return query(2*n+1, mid+1, j,s,e,flag);
 	 else if( e<=mid )
 	 	return query(2*n,i,mid,s,e,flag);
 	 else{
 	 	return query(2*n,i,mid,s,mid,flag) + query(2*n+1, mid+1,j,mid+1,e,flag) ;
 	 }

 }
 
 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d,q;
	
	get(n);
	get(q);
	while(q--){
		get(z);
		get(a);
		get(b);		

		if(z){
			cout << query(1,1,n,a+1,b+1,0) << endl;
		}else{
			update(1,1,n,a+1,b+1);
		}	
	}
 
	
 
	return 0;
} 
