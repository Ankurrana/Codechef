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
#include <climits>

typedef long long int lld;
typedef long int ld;
using namespace std;
 

#define getw getchar_unlocked
#define iterate(n) for(lld i=0;i<n;i++)
#define d_iterate(p,q) for(lld i=p;i<=q;i++)
#define r_iterate(n,z) for(lld i=n-1;i>=n-z;i--) /* z number of elements to the left of n */
#define p(n) printf("%lld\n",n);
#define get(n) n = scan2();
#define print_array(k,n) iterate(n){ p(k[i]);}
#define ps(s) printf("%s\n",s);
#define mp make_pair;
#define pb push_back;

 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	
	string str;
	cin >> str;
	lld length = str.length();
	lld num[100010];

	iterate(length){
		num[i] = (int)(str[i] - '0');
	}
		
	

	
 
	
 
	return 0;
} 

