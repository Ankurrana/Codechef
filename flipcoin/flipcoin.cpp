#include<bits/stdc++.h>
using namespace std;
#ifdef _WIN32
#include<conio.h>
#endif
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;
#define FOR(i,a,b) for(int i=(a);i< (b);i++)
#define input(a) scanf("%d",&a)
#define CLEAR(a) memset((a),0,sizeof(a))
#define INF 1000000000
#define LL long long
#define PI 2*acos(0.0)
#define sqr(a) (a)*(a)

struct segTree
{
	int flip,len;
};
segTree tree[MAX];
inline void update(int n,int b,int e,int i,int j)   
{
	// #n : index (starting from 1 )
	// #b and #e are the range indexes
	// #i and #j are the range to be updated
 
	if( b>e||b>j||e<i )   // out of range , things that aren't possible.
	 return;
	if(b==i && e==j)   //the exact range is found.
	{
		tree[n].flip++;
		tree[n].len =(e-b+1)-tree[n].len;   
		// in case a range is flipped, the number of heads are exchnged with tails. or (e-b+1)-tree[n].len
		//the flag #flip is only updated for the exact range val and no one else.
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
int main()
{
	int n,q;
	#ifdef _WIN32
	input(n);
	input(q);
	#endif
	#ifdef ONLINE_JUDGE
	n=read();
	q=read(); 
	#endif
	int op,a,b;
	while(q--)
	{
		#ifdef _WIN32
		scanf("%d %d %d",&op,&a,&b);
		#endif
		#ifdef ONLINE_JUDGE
	    op=read();
	    a=read(); 
	    b=read();
		#endif
		if(op==1)
		{		
			int res=query(1,0,n-1,a,b,0);
			printf("%d\n",res);
		}
		else
		{
			update(1,0,n-1,a,b);
		}
	}
	return 0;
}