     #include<stdio.h>
    #include<math.h>
    #include<string.h>
    #include<set>
    #include<algorithm>
    #include<iostream>
     
    using namespace std;
    double result[26][26];
     
    void multiply(double a[26][26],double b[26][26])
    {int i,j,k;
    for(i=0;i<26;i++)
    {for(j=0;j<26;j++)
    {result[i][j]=0;
    for(k=0;k<26;k++)
    {result[i][j]+=a[i][k]*b[k][j];}
    }
    }
     
    }
     
     
    void copy(double a[26][26],double b[26][26])
    {int i,j;
    for(i=0;i<26;i++)
    {for(j=0;j<26;j++)
    {a[i][j]=b[i][j];}
    }
    }
     
    void power(double x[26][26],double a[26][26],int n) //x=a^n
    {
    double b[26][26],c[26][26],d[26][26];
    copy(b,a);
    int i,j;
    for(i=0;i<26;i++)
    {for(j=0;j<26;j++)
    {if(i==j)
    {c[i][j]=1;}
    else
    {c[i][j]=0;}
    }
    }
     
    while(n)
    {if(n&1)
    {
    multiply(c,b);
    copy(c,result);
    }
    multiply(b,b);
    copy(b,result);
    n=n>>1;
    }
     
    copy(x,c);
    }
     
    void mul_arr(double m1[26][26],double m2[26][26],double m3[26][26],int row,int col)
{
    int i,j,k;
    for(i=1;i<=row;i++)
    {
    for(j=1;j<=col;j++)
    {
    for (k=1;k<=row;k++)
    {
    m3[i][j] = m3[i][j] + (m1[i][k] * m2[k][j]);
    }
    }
    }
} 
     
     
     
    int main()
     
    {
    int t,n,k,i,j;
    double a[26][26];
    set<string> myset;
    set<string>::iterator it;
    scanf("%d",&t);
    double keep[26][26];
    // char str[100001];
    string str,input;
    while(t--)
    {
    scanf("%d%d",&n,&k);
    cin>>str;
     
    for(i=0;i<=25;i++)
    {
    for(j=0;j<=25;j++)
    {
    scanf("%lf",&a[i][j]);
    keep[i][j]=a[i][j];
    }
    }

    // input matrix a ...raise to power k
    int c,d,p,q;
    double multiply[26][26];
    double sum=0;
     
 
 double m3[26][26];
 
 if(k==1)
 {
 	copy(m3,a);
 }
 
 if(k==2)
 {
 	    mul_arr(a,a,m3,26,26);
 }
 
 if(k==3)
 {
 	 mul_arr(a,a,m3,26,26);
 	 mul_arr(a,m3,m3,26,26);
 }
 
 
 
 
 
 //   power(result,a,k);
    /*
    for(i=0;i<5;i++)
    {
    for(j=0;j<5;j++)
    {
    printf("%lf ",result[i][j]);
    }
    printf("\n");
    }
    */
    double ans=0;
    string input;
     
    for(i=0;i<n;i++)
    {
    cin>>input;
    myset.insert(input);
    }
    

    for (it=myset.begin(); it!=myset.end(); ++it)
    {
    double prod=0;
    if((*it).size()==str.size())
    {
    prod=1;
    for(j=0;j<str.size();j++)
    {
    prod=prod*a[str[j]-'a'][(*it)[j]-'a'];
    }
    ans=ans+prod;
    }
    }
     
    printf("%lf\n",ans);
    }
    return 0;
    } 