#include <bits/stdc++.h>//Accepted

using namespace std;

int main()
{
    freopen("1214. Large Division.txt","r",stdin);
    long long int t,c=0,b,l,i,j,v;
    string a;

    scanf("%lld",&t);

    while(t--)
    {
        cin>>a;
        scanf("%lld",&b);

        l=a.length();
        i=0;
        v=0;

        if(a[0]=='-')
        {
            i=1;
        }
        if(b<0)
        {
            b=b*(-1);
        }
        for(;i<l;i++)
        {
            v=v*10+a[i]-'0';
            v=v%b;
        }

        printf("Case %lld: ",++c);
        if( v == 0 )
        {
            printf("divisible\n");
        }
        else
        {
            printf("not divisible\n");
        }
    }
    return 0;
}
