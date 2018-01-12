#include<stdio.h>//Accepted
#include<math.h>
#define PI acos(0.0)

int main()
{
    freopen("1072. Calm Down.txt","r",stdin);
    int t,n,c=0;
    double R,p,x,area,k,v,a;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%lf %d",&R,&n);
        printf("Case %d: ",++c);

        v=cos((2*PI)/n);
        x=R/v;
        p=x*x-R*R;
        p=sqrt(p);

        area=p*R;
        k=p+x;

        printf("%.6lf\n",area/k);

    }
    return 0;
}
