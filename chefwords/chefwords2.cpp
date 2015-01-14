#include<bits/stdc++.h>
using namespace std;
double d[130][130];
char s[2000][2000],s1[2000][2000];
#define pb push_back

vector<double> vx;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,k,i,j,m,xx;
      cin>>n>>k;
      //  for(i=0;i<k;i++)
xx=k;
k=1;
            scanf("%s",s[0]);
        for(i=97;i<123;i++)
            for(j=97;j<123;j++)
            cin>>d[i][j];
 
 double ans=0;
        for(i=0;i<n;i++)
         scanf("%s",s1[i]);
         for(i=0;i<k;i++)
         {
             int l1=strlen(s[i]),l2;
             double re=1.0,mx=0.0;
            for(j=0;j<n;j++)
            {
		re=1.0;
                l2=strlen(s1[j]);
                if(l1==l2)
                {
                    for(m=0;m<l2;m++)
                    {
			//	cout<<d[s[i][m]][s1[j][m]]<<endl;
                        re=re*d[s[i][m]][s1[j][m]];
                    }
                    mx+=re;
                }

           }
//vx.pb(mx);
cout<<k*mx<<endl;
//printf("%.10f\n",mx);
//cout<<mx<<endl;
         }

 

vx.clear();
 
    }
    return 0;
} 