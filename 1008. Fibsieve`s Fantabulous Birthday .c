#include<stdio.h>//Accepted
#include<math.h>
#define lld unsigned long long int

int main()
{
    lld n,T,x,p,row,col,c=0;

    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld",&n);

        x=ceil(sqrt(n));
        p=1+x*(x-1);

        if(n==p)
        {
            row=col=x;
        }
        else if(x%2==0)
        {
            if(n>p)
            {
                row=x-(n-p);
                col=x;
            }
            else
            {
                col=x-(p-n);
                row=x;
            }
        }
        else
        {
            if(n<p)
            {
                row=x-(p-n);
                col=x;
            }
            else
            {
                col=x-(n-p);
                row=x;
            }
        }
        printf("Case %lld: %lld %lld\n",++c,col,row);
    }
    return 0;
}
