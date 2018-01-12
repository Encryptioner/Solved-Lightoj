#include<bits/stdc++.h>//Accepted
#define MAX 110
using namespace std;

int main()
{
    freopen("1133. Array Simulation.txt","r",stdin);
    int t,i,j,v,c=0,n,m,y,z,k,count;
    bool x;
    string mth;
    int d;
    int nth[MAX];

    scanf("%d",&t);
    while(t--)
    {
        count=0;
        d=1;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&nth[i]);
        }
        while(m--)
        {
            k=0;
            cin>>mth;

            if(mth=="R")
            {
                count++;
            }
            else if(mth=="P")
            {
                scanf("%d %d",&y,&z);
                if( (count&1) == 0 )
                {
                    swap(nth[y],nth[z]);
                }
                else
                {
                    swap(nth[n-1-y],nth[n-1-z]);
                }
            }
            else if(mth=="D")
            {
                scanf("%d",&k);
                for(i=0;i<n;i++)
                {
                    nth[i]=(nth[i]*d);
                    nth[i]/=k;
                }
                d=1;
            }
            else if(mth=="M")
            {
                scanf("%d",&k);
                d*=k;
            }
            else
            {
                scanf("%d",&k);
                for(i=0;i<n;i++)
                {
                    nth[i]=nth[i]*d+k;
                }
                d=1;
            }
        }

        printf("Case %d:\n",++c);
        if( (count&1) == 0 )
        {
            for(i=0;i<n-1;i++)
            {
                printf("%d ",nth[i]*d);
            }
            printf("%d\n",nth[i]*d);
        }
        else
        {
            for(i=n-1;i>0;i--)
            {
                printf("%d ",nth[i]*d);
            }
            printf("%d\n",nth[i]*d);
        }
    }
    return 0;
}

