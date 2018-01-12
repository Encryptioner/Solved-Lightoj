#include<bits/stdc++.h>//Accepted
#define lld unsigned long long int

using namespace std;

int main()
{
    freopen("1042.  Secret Origins.txt","r",stdin);
    int t,c=0;
    lld N,N1,v;

    scanf("%d",&t);

    while(t--)
    {
        string arr;
        int ans[10000];
        int i=0,j,count0=0,count1=0,start0,v1=0,pre1,new1,num0,pos0,pos1,x=1;
        bool case4=false,case3=true;
        scanf("%lld",&N);

        printf("Case %d: ",++c);
        N1=N;
        while(N>0)
        {
            v=(N&1);
            ans[i]=v;

            N=N>>1;
            i++;

            v1=v;
            if(v==1)
            {
                count1++;
            }
            else
            {
                count0++;
                if(count1>0)
                {
                    case3=false;
                }
            }
            if(count1==1 && x==1)
            {
                num0=count0;
                pos1=i-1;
                x=0;
            }
            if(count1>=1 && count0==num0+1 && case4==false)
            {
                pos0=i-1;
                ans[pos1]=0;
                ans[pos0]=1;
                case4=true;
            }
        }
        if(count1==1)
        {
            printf("%lld\n",N1<<1);
        }
        else if(count0==0)
        {
            v=pow(2,(count1-1));

            printf("%lld\n",N1+v);
        }
        else if(case3==true)
        {
            v=1;
            for(j=1;j<count1-1;j++)
            {
                v+=pow(2,j);
            }
            v+=pow(2,i);
            printf("%lld\n",v);
        }
        else
        {
            v=0;
            x=0;

            for(j=pos0-1;j>0;j--)
            {
                if(ans[j]==1)
                {
                    v+=pow(2,x);
                }
                x++;
            }
            for(j=pos0;j<i;j++)
            {
                if(ans[j]==1)
                {
                    v+=pow(2,j);
                }
            }
            printf("%lld\n",v);
        }
    }
    return 0;
}
