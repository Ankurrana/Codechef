#include "bits/stdc++.h"
#include "string"
using namespace std;

typedef long long int lld;


#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=e ; i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

template < typename T >
inline void geta(T *a){
	T n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	*a = n*s;
}

bool iswithinrange(lld p, lld l,lld r){
	if(p>=l && p<=r) return true;
	return false;
}


class Number{
public:
	lld k;
	lld p;
	Number(lld _k, lld _p):k(_k),p(_p){};
	Number(){};
};

bool operator<(const Number & a, const Number & b){
	return a.k < b.k; // increasing order sort
}

int main(){
	lld i,j,t,n;
	lld p,q,k,z,l;




	Number L[50001];
	Number R[50001];
	lld leftsum = 0;
	lld rightsum = 0;
	lld diff;
	get(n);



	iterate(n/2){
		get(L[i].k);
		L[i].p = i + 1;
		leftsum += L[i].k;
	}


	iterate(n/2){
		get(R[i].k);
		R[i].p = n/2  + i + 1;
		rightsum += R[i].k;
	}


	if(leftsum > rightsum){
		diff = leftsum - rightsum;

		iterate(n/2){
			Number temp(L[i].k,L[i].p);
			L[i].k = R[i].k;
			L[i].p = R[i].p;
			R[i].k = temp.k;
			R[i].p = temp.p;
		}



	}else{ 
		diff = rightsum - leftsum;
	}



	sort(L,L + n/2);
	sort(R,R + n/2);

 	lld minimum = 1e14;
 	lld Rindex , Lindex;
 	bool solfound = false;

 	lld leftrange = 1;
 	lld rightrange = diff-1;

 	lld Current_Nearness = diff; // Current nearness to the diff/2;

		//The right side one is higher than the left one
		for(i=n/2-1;i>=0 && (!solfound) ;i--){
			lld RNumber = R[i].k;
			lld l = 0;
			lld r = n/2-1;			
			while(r>l){	
				lld mid = (l+r)/2;
				lld LNumber = L[mid].k;
				lld Current_Difference = RNumber - LNumber;
				if(Current_Difference < 0){ 
					r = mid-1;
					continue;
				}
				if( Current_Difference > diff){ 
					l = mid+1;
					continue;
				}else{
					if(Current_Difference > 0 && Current_Difference < diff){
							if(  labs(Current_Difference - diff/2) < minimum ){
								minimum = labs(Current_Difference - diff/2);
								Rindex = R[i].p;
								Lindex = L[mid].p;
							}
							if(Current_Difference == diff/2){
								solfound = true;
								Rindex = R[i].p;
								Lindex = L[mid].p;
								break;
							}
					}
					if(Current_Difference > diff/2){
						l = mid + 1;
					}else{
						r = mid - 1;
					}
				}
			}



	}





	if( Lindex>Rindex ){
		swap(Lindex,Rindex);
	}

	lld ans = 1 ;
	ans += Rindex - (n/2 + 1);
	ans++;
	

	printf("%lld\n",ans);

	printf("%lld %lld\n",Lindex,n/2 );

	lld u = Rindex - 1;
	while(u>=((n/2)+1)){
		printf("%lld %lld\n",u,u+1 );
		u--;
	}

	printf("%lld %lld\n",n/2,n/2+1 );




	return 0;
}

// if( Current_Difference < diff ){
						
// 						if( labs(Current_Difference - diff/2) < minimum  ){
// 							minimum = labs(Current_Difference - diff/2);
// 							Rindex = R[i].p;
// 							Lindex = L[mid].p;
// 							if(bestsol == 0){
// 								solfound = true;
// 								break;
// 							}

// 						}
// 						if(Current_Difference > diff/2){
// 							l = mid + 1;
// 						}
// 						if(Current_Difference < diff/2){
// 							r = mid - 1;
// 						}		
// 					}