#include<stdio.h>//Accepted
#define PI 2*acos(0.0)

int main()
{
    freopen("1022. Circle in Square.txt","r",stdin);
    int t,c=0;
    double r,ans;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&r);
        printf("Case %d: ",++c);
        printf("%.2lf\n",(r*r*4)-(2*acos(0.0)*r*r));
    }
    return 0;
}
