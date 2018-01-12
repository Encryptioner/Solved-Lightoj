#include<bits/stdc++.h>//Accepted

using namespace std;

int main()
{
    int t,cas=0,n,i,temp,cnt,x;

    scanf("%d",&t);
    while(t--)
    {
        vector<int>a;
        cnt=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            a.push_back(temp);
        }
        if(a[0]>2)//if first  taken input is taken after all ready he has lied
        {
            temp=a[0]-2;
            cnt+=(temp/5);

            if(temp%5!=0)
            {
                cnt++;
            }
        }
        for(i=1;i<n;i++)
        {
            if(a[i]>a[i-1])//at least a lie has been spoken
            {
                temp=a[i]-a[i-1];//As nose grows at least 1 cm and at most 5 cm
                cnt+=(temp/5);//cnt>0 if one or more than one lie has told

                if(temp%5!=0)//as 5/5=1 and it was count previous, then for (1-4) an increase of count
                {
                    cnt++;
                }
            }
        }
        printf("Case %d: ",++cas);
        printf("%d\n",cnt);
    }
}
