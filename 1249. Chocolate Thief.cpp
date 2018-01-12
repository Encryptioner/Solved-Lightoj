#include<bits/stdc++.h>//Accepted
using namespace std;

int main()
{
    int t,cas=0,x,y,temp,l,w,h,i,j,big,small,n;
    string str;

    scanf("%d",&t);

    while(t--)
    {
        vector<string>S;
        big=-111234;
        small=100000000;

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>str;
            S.push_back(str);
            scanf("%d %d %d",&l,&w,&h);
            temp=l*w*h;
            if(temp<small)
            {
                small=temp;y=i;
            }
            if(temp>big)
            {
                big=temp;x=i;
            }
        }
        printf("Case %d: ",++cas);
        if(small==big)
        {
            printf("no thief\n");
        }
        else
        {
            cout<<S[x]<<" took chocolate from "<<S[y]<<"\n";
        }
    }
    return 0;
}
