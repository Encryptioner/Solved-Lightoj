#include <stdio.h>//Accepted
#include <math.h>

int main()
{
    freopen("1305. Area of a Parallelogram.txt","r",stdin);
    int i,j,t,c=0,ax,ay,bx,by,cx,cy,dx,dy,u,v,ans,arrx[5],arry[5];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);

        arrx[1]=ax,arry[1]=ay,
        arrx[2]=bx,arry[2]=by,
        arrx[3]=cx,arry[3]=cy;

        dx=ax+(cx-bx);
        dy=ay+(cy-by);
        arrx[0]=dx,arry[0]=dy;
        arrx[4]=dx,arry[4]=dy;

        u=0,v=0;
        for(i=1;i<=4;i++)
        {
            u+=arrx[i-1]*arry[i];
            v+=arry[i-1]*arrx[i];
        }
        ans=abs(u-v);
        printf("Case %d: ",++c);
        printf("%d %d %d\n",dx,dy,(ans>>1) );
    }
    return 0;
}
