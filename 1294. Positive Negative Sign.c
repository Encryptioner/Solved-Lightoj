#include <stdio.h>//Accepted

int main()
{
    freopen("1294. Positive Negative Sign.txt","r",stdin);
    unsigned long long int t,c=0,n,m;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&m);

        printf("Case %lld: %lld\n",++c,((n*m)>>1) );
    }
    return 0;
}
