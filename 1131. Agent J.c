#include<stdio.h>//Accepted //creating triangle by centre of 3 circles
#include<math.h>
#define pi acos(-1.0)
int main()
{
    int cas=0,t;
    double r1,r2,r3,a,b,c,s,n1,n2,n3;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        a=r1+r2;
        b=r1+r3;
        c=r2+r3;
        s=(a+b+c)/2;
        s=s*(s-a)*(s-b)*(s-c);
        s=sqrt(s);//area of circle

        n1=a*a+b*b-c*c;
        n1/=2*a*b;
        n1=acos(n1);
        n1=(n1*180)/pi;;
        n1=(n1*pi*r1*r1)/360;//area of circle having r1 radius in the triangle

        n2=c*c+a*a-b*b;
        n2/=2*c*a;
        n2=acos(n2);
        n2=(n2*180)/pi;
        n2=(n2*pi*r2*r2)/360;

        n3=b*b+c*c-a*a;
        n3/=2*b*c;
        n3=acos(n3);
        n3=(n3*180)/pi;
        n3=(n3*pi*r3*r3)/360;

        printf("Case %d: %.10lf\n",++cas,s-(n1+n2+n3));//subtracting total area covered by 3 circle in triangle. Left over area of triangle is answer
    }
    return 0;
}
