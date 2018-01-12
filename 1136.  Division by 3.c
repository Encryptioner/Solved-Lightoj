#include<stdio.h>//Accepted

int main()
{
    freopen("1136.  Division by 3.txt","r",stdin);
    long long int t,n1,n2,v1,N1,N2,v2,ans,c=0;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n1,&n2);

        v1=(n1%3);
        v2=(n2%3);

        n1=n1-v1;
        n2=n2+(3-v2);

        ans=((n2-n1)/3)*2;
        //printf("%lld %lld %lld %lld %lld\n",n1,n2,v1,v2,ans);
        if(v1==0)
        {
            ans+=1;
        }
        if(v2==1 || v2==0)
        {
            ans-=2;
        }
        if(v2==2)
        {
            ans-=1;
        }
        printf("Case %lld: %lld\n",++c,ans);
    }
    return 0;
}
