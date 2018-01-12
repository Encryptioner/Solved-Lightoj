#include<bits/stdc++.h>//Accepted
#define PI acos(-1)
using namespace std;

int main()
{
    int T,c=0;
    double r1,r2,h,p,x,v1,v2,h2;

    scanf("%d",&T);
    while(T--)
    {
        cin>>r1>>r2>>h>>p;
        x=((r1-r2)*p)/h;
        x+=r2;//radius of the upper point of juice

        h2=(r2*p)/(x-r2);//if it is a conic then missing height
        v1=PI*x*x*(h2+p);
        v1/=3;//volume of the full conic
        v2=PI*r2*r2*h2;
        v2/=3;//volume of the missing conic part

        printf("Case %d: %.10f\n",++c,v1-v2);
    }
    return 0;
}
