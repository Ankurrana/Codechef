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



/*
		Here starts the BIT

*/
inline void update(int n,int b,int e,int i,int j)  //coins are flipped from i to j
{
	if(b>e||b>j||e<i)
	 return;
	if(b==i&&e==j)
	{
		tree[n].flip++;
		tree[n].len =(e-b+1)-tree[n].len;
		return;
	}
	int mid=(b+e)>>1;
	if(i>mid)
	  update(2*n+1,mid+1,e,i,j);
	else if(j<=mid)  
	  update(2*n,b,mid,i,j);
	else
	{
		update(2*n,b,mid,i,mid);
		update(2*n+1,mid+1,e,mid+1,j);
	}
	tree[n].len=tree[2*n].len+tree[2*n+1].len;
	if(tree[n].flip%2==1)
	   tree[n].len =(e-b+1)-tree[n].len;
}
int query(int n,int b,int e,int i,int j,int cnt)
{
	if(b>e||b>j||e<i)
	  return 0;
	if(b==i&&e==j)
	{
		if(cnt%2==0)
		  return tree[n].len;
		else
		  return (e-b+1-tree[n].len);
	}
	cnt +=tree[n].flip;
	int mid=(b+e)>>1;
	if(i>mid)
	   return query(2*n+1,mid+1,e,i,j,cnt);
	else if(j<=mid)
	   return query(2*n,b,mid,i,j,cnt);
	else
	{
	   int q1=query(2*n,b,mid,i,mid,cnt);
	   int q2=query(2*n+1,mid+1,e,mid+1,j,cnt);
	   return q1+q2;	
	}
}








/*
	Here it ends
*/


 
lld powermod(lld a,lld b,lld m){  // pow(a,b)%m
	lld result = 1;
	while(b>0){
		if(b&1)
			result = (result * a)%m;
		a = (a * a)%m;
		b = b>>1; //b= b/2;
	}
	return result;

}


lld sumuptox(lld n,lld a,lld d,lld r,lld mod){
	lld ans = 0;
	ans =  (a/(1-r));
	ans += (((d*r)*( 1 - powermod(r,n-1,mod))) / ((1-r)*(1-r)));
	ans -= (((a+(n-1)*d)*powermod(r,n,mod)) / (1-r));
	return ans;
}



 

 
lld solve(lld n){
	lld i = 0;
	lld ans = 0;
	lld b,c,d,k,j;
 
	return ans;
}
 


lld agsqaure(lld index, lld power,lld mod){
	//Basically first access the element,lets its value be val. now determine val^power - val
	//input index is 1 based;
	index--;
	intersum(0,)
} 


 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld b,c,d;

 
	// cout << sumofagp(3,3,2,3,2,100000);
 	


 	a[0] = 1;
 	a[1] = 2;
 	a[2] = 3;
 	a[3] = 4;
 	a[4] = 5;

 	creatept(0,0,4);

 	// iterate(10)
 	// 	cout << pt[i] << endl;


 	cout << intersum(0,0,4,1,1,10000);

	return 0;
} 
