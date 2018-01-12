#include<stdio.h>//Accepted
#include<math.h>

int main()
{
    freopen("1069. Lift.txt","r",stdin);
    int t,y,l,c=0,v;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&y,&l);

        printf("Case %d: ",++c);

        if(y==0)
        {
            printf("0\n");
        }
        else
        {
            v=fabs(y-l);

            printf("%d\n",(v<<2)+(y<<2)+19);
        }
    }
    return 0;
}
