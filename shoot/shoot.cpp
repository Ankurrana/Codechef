//Seriously!! you want to read my code!! don't you have any other work??
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <string>
using namespace std;
typedef long long LL;
#define IT iterator
#define getcx getchar
#define INF (int(1e9))
#define INFL (LL(1e18))
#define pii pair< int,int >
#define piii pair< pii , int >
#define temp 0
#define wait 1
#define perm 2
struct comp
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.second>b.second;
    }
};
struct myclass {
  bool operator() (const pii &a,const pii &b)
  {
        return a.first>b.first;
  }
} myobject;
#define in2(n,m) scanf("%d %d",&n,&m);
#define in3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define mod 1000000007
inline void in(int &n)
{
    n=0; int ch = getcx(); int sign = 1;
    while(ch < '0' || ch > '9') { if(ch == '-') sign=-1; ch = getcx(); }
    while(ch >= '0' && ch <= '9') { n = (n << 3) + (n << 1) + ch - '0', ch = getcx(); }
    n = n * sign;
}
int f[10004];
int state[10004],level[10004];
int main()
{
    int start,stop;
    int t,n,i,p,q,node,ml,idx,v;
    vector<int> adj[10004];
    queue<int> Q;
    in(t);
    while(t--)
    {
        in(n);
        for(i=0; i<=n; i++)
        {
            f[i]=0;
            adj[i].clear();
        }
 
        for(i=1; i<=n-1; i++)
        {
            in(p);
            in(q);
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
 
        for(i=0; i<=n; i++)
            state[i]=temp;
 
        ml=-1;
        Q.push(1);
        state[1]=perm;
        level[1]=0;
        while(!(Q.empty()))
        {
            v=Q.front();
            if(level[v]>ml)
            {
                ml=level[v];
                idx=v;
            }
            Q.pop();
            for(i=0; i<adj[v].size(); i++)
            {
                node=adj[v][i];
                if(state[node]==temp)
                {
                    state[node]=perm;
                    Q.push(node);
                    level[node]=level[v]+1;
                }
            }
        }
        start=0;
        stop=ml;
        for(i=1; i<=n; i++)
        {
            f[level[i]]++;
        }
        int ans=0;
        while(1)
        {
            //printf("start and stop is %d %d\n",start,stop);
            ans++;
            start++;
            if(start>stop)
                break;
            ans++;
            f[stop]--;
            //printf("stop is %d anf f is %d\n",stop,f[stop]);
            if(f[stop]<=0)
            {
                stop--;
            }
            if(start>stop)
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}