#include<bits/stdc++.h>//Accepted

using namespace std;

int main()
{
    int t,n,m,c=0,x,i;
    string str;
    scanf("%d",&t);

    while(t--)
    {
        deque<int>d;
        printf("Case %d:\n",++c);
        scanf("%d %d",&n,&m);

        for(i=1;i<=m;i++)
        {
            cin>>str;

            if(str[1]=='u'){
            scanf("%d",&x);
            if(d.size()==n)
            {
                printf("The queue is full\n");
                continue;
            }
            if(str[4]=='L')
            {
                d.push_front(x);
                printf("Pushed in left: %d\n",x);
                continue;
            }
            else
            {
                d.push_back(x);
                printf("Pushed in right: %d\n",x);
                continue;
            }
            }

            else{
            if(d.empty())
            {
                printf("The queue is empty\n");
                continue;
            }
            if(str[3]=='L')
            {
                x=d.front();
                d.pop_front();
                printf("Popped from left: %d\n",x);
                continue;
            }
            else
            {
                x=d.back();
                d.pop_back();
                printf("Popped from right: %d\n",x);
                continue;
            }}
        }
    }
    return 0;
}
