#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(lld (i) = s ; (i)<=d ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

int main(){
    ios::sync_with_stdio(false);
    long int i,j,t,n;
    long int p,q,k,z,l,x,y;
    long int f[10];
    get(x);
    get(y);

    int MOD = 1000000007;

    f[0] = x;
    f[1] = y;
    f[2] = y-x;
    f[3] = 0-x;
    f[4] = 0-y;
    f[5] = x-y;



    get(n);
    n--;

    cout << (f[n%6]%MOD + MOD)%MOD ; 
    

    return 0;
}