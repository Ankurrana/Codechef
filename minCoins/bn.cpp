// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50	
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
 
using namespace std;
int donations[] =   { 10, 3, 2, 5, 7, 8 };
int N = sizeof(donations)/ sizeof(donations[0]);
int dp[50];
 
int main(int argc, char const *argv[])
{
    /* 
    There are two main cases to be considered here.
    1. Include element at index 0.
        - This leads us to not pick the last element since it is cyclic in nature. 
    2. Include element at index 1.
        - In this case, we can pick the last element.
 
    but whether we pick the element at i, depends on the following condition:
        dp[i] = max(dp[i-2] + donations[i], dp[i-1])
    which basically states, is it in our interest to pick the current donation and 
    drop the donation offered by the previous neighbor.
 
    We pick the max of both cases stated earlier.
    */
 
    memset(dp, 0, sizeof(dp));
    dp[0] = donations[0]; 
    
    for (int i = 2; i < N-1; ++i)
    {
        dp[i] = max(dp[i-2] + donations[i], dp[i-1]);
    }
    
    int ans1 = dp[N-2];
 
    memset(dp, 0, sizeof(dp));
    dp[1] = donations[1];
 
    for (int i = 2; i < N; ++i)
    {
        dp[i] = max(dp[i-2] + donations[i], dp[i-1]);
    }
    int ans2 = dp[N-1];
    
    cout << max(ans1, ans2);
    cout << endl;
    return 0;
}

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
 

 

 
lld solve(lld n){
    lld i = 0;
    lld ans = 0;
    lld a,b,c,d,k,j;
 
    return ans;
}
 

 
 
int main(){
    lld i,z,n,j,k,t,h,ans = 0;
    lld a,b,c,d;
    get(t);
    
    while(t--){
        
                
    }
 
    
 
    return 0;
} 

/*
    By Ankur Rana (ankurmarshall)

*/