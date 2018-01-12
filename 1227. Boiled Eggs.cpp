#include<bits/stdc++.h>//Accepted

using namespace std;

int main()
{
    int t,cas=0,cnt,i,j,n,p,q,w,sum;

    scanf("%d",&t);

    while(t--)
    {
        sum=0,cnt=0;
        scanf("%d %d %d",&n,&p,&q);

        for(i=0;i<n;i++)
        {
            scanf("%d",&w);
            sum+=w;
            if(sum<=q && cnt<p)//both weight and number of egg is ok
            {
                cnt++;
            }
        }
        printf("Case %d: ",++cas);
        printf("%d\n",cnt);
    }

    return 0;
}
