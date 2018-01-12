#include<stdio.h>//Accepted
#define MAX 1010
#define lld long long int

int main()
{
    freopen("1015.  Brush (I).txt","r",stdin);
    int t,n,i,c=0,arr;
    lld ans;

    scanf("%d",&t);

    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        printf("Case %d: ",++c);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr);
            if(arr>0)
            {
                ans+=arr;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
