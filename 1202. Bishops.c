#include<stdio.h>//Accepted
#include<math.h>
int main()
{
    freopen("1202. Bishops.txt","r",stdin);

    unsigned int t, r1,r2,c1,c2,c=0,color1,color2,v1,v2;

        scanf("%d",&t);

        while(t--)
        {
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            printf("Case %d: ",++c);

            color1=1,color2=1;

            if( ( (r1&1)==0 && (c1&1)==0 ) || ( (r1&1)!=0 && (c1&1)!=0 ) )
            {
                color1=0;
            }
            if( ( (r2&1)==0 && (c2&1)==0 ) || ( (r2&1)!=0 && (c2&1)!=0 ) )
            {
                color2=0;
            }

            if(color1!=color2)
            {
                printf("impossible\n");
            }
            else if( (int)abs(r1-r2)==(int)abs(c1-c2) )
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
            }
        }
    return 0;
}
