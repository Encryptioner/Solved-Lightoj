#include<bits/stdc++.h>//Accepted
#define pi acos(-1)
using namespace std;

int main()
{
    int t,cas=0,i,j,Ox,Oy,Ax,Ay,Bx,By;
    double angle,temp,ans,r1,r2,d;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&Ox,&Oy,&Ax,&Ay,&Bx,&By);
        r1=(Ox-Ax)*(Ox-Ax)+(Oy-Ay)*(Oy-Ay);
        r1=sqrt(r1);

        r2=(Ox-Bx)*(Ox-Bx)+(Oy-By)*(Oy-By);
        r2=sqrt(r2);

        d=(Bx-Ax)*(Bx-Ax)+(By-Ay)*(By-Ay);
        d=sqrt(d);

        angle=(r1*r1)+(r2*r2)-(d*d);
        temp=(2*r1*r2);
        angle/=temp;
        angle=acos(angle);//angle is found in radian
        angle*=180;
        angle/=pi;//angle is found in degree

        ans=pi*r1;//r1==r2 in circle
        temp=angle/180;
        ans*=temp;//as 360 degree covers 2*pi*r, angle degree covers ans

        //cout<<r1<<" "<<r2<<" "<<d<<" "<<angle<<" "<<temp<<"\n";

        printf("Case %d: ",++cas);
        printf("%.5lf\n",ans);
    }

    return 0;
}
