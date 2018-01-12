#include<stdio.h>//Accepted

int main()
{
    freopen("1107. How Cow.txt","r",stdin);
    int t,x1,y1,x2,y2,x,y,c=0,m;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);
        printf("Case %d:\n",++c);
        while(m--)
        {
            scanf("%d %d",&x,&y);
            if( (x1<x) && (x<x2) && (y1<y) && (y<y2) )
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}


