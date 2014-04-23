#include "iostream"
#include "cstdio"
using namespace std;
#define iterate(n) for(int i = 0;i < (n);i++)

typedef long long int lld;



lld pt[2000010];
lld a[1000001];

lld creatept(lld index,lld start, lld end){
	lld mid = (start+end)/2;

	// cout << "Division at : " << start << ", " << mid << "and " << mid+1 << ", " << end << endl; 
 
	if( start == end ){
		pt[index] = a[start];
		return a[start];
	}


	pt[index] = creatept( 2*index+1 , start , mid ) + creatept( 2*index+2 , mid+1 , end );

	return pt[index];
}


void deleteM(lld index,lld start, lld end,const int z_index,lld value){
	//For deleting k marbles from the ith indexed kid
	//Initially start = 0 , and end = n;
	if( start == end && start == z_index){
		pt[index] -= value; 
		return ;
	}

	if( z_index >= start && z_index <=end )
			pt[index] -= value;

	lld mid = (start+end)/2;

	if( z_index <= mid ){
		deleteM( 2*index+1,start,mid,z_index,value);
		// cout << "Division at : " << start << ", " << mid << endl; 
	}
	else if( z_index >= (mid+1) ){
		deleteM( 2*index+2,mid+1,end,z_index,value );
		// cout << "Division at : " << mid+1 << ", " << end << endl; 
	}

}


lld intersum(lld index, lld start, lld end, lld l,lld r){
	if( (r < start) || l>end )
		return 0;
	if( start>=l && end<=r )
		return pt[index];


	lld  mid = (start+end)/2;

	return intersum(2*index+1,start,mid,l,r) + intersum(2*index+2,mid+1,end,l,r);


}

int main(){
	// a[0] = 1;
	// a[1] = 2;
	// a[2] = 3;

	// creatept(0,0,2);
	// deleteM(0,0,2,2,-1);

	// cout << intersum(0,0,2,0,1);
	// iterate(5)
		// cout << pt[i] << endl; 

	lld i,j,k,l,x,y;
	lld n,q;
	char c;
	scanf("%lld %lld ",&n,&q);
	iterate(n)
		scanf("%lld",&a[i]);

	creatept(0,0,n-1);

	iterate(q){
		// cout << "instide this hsit" << endl;
		cin >> c;
		// cin >> x;
		// cin >> y;
		// gets(c);
		scanf("%lld %lld",&x,&y);
		if( c=='S')
			printf("%lld\n",intersum(0,0,n-1,x,y));
		else if(c=='G')
			deleteM(0,0,n-1,x,-1*y);
		else
			deleteM(0,0,n-1,x,y);
	}



	return 0;
}