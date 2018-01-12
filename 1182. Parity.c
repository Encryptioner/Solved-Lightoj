#include <stdio.h>//Accepted
#include <math.h>

int main()
{
    freopen("1182. Parity.txt","r",stdin);
    unsigned int n,t,c=0,count,i,j,x;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        count=0;

        while(n>=1)
        {
            x=log2(n);
            n=n-pow(2,x);
            ++count;
        }
        printf("Case %d: ",++c);
        if( (count&1) == 0 )
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
    }
    return 0;
}
