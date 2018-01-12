#include<bits/stdc++.h>//Accepted
using namespace std;

int main()
{
    int t,cas=0,temp,i,j,x,n,m,k,p;
    bool wish,given;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);

        int arr[n][m],sol[m];

        for(i=0;i<n;i++)
        {
            memset(arr[i],0,m*sizeof(int));
            for(j=0;j<k;j++)
            {
                scanf("%d",&temp);
                x=abs(temp);

                if(temp<0){temp=-1;}
                else{temp=1;}

                if(arr[i][x-1]==0){arr[i][x-1]=temp;}//as array count starts from 0
                else if(arr[i][x-1]==-1 && temp==-1)
                {
                    arr[i][x-1]=temp;
                }
                else if(arr[i][x-1]==1 && temp==1)
                {
                    arr[i][x-1]=temp;
                }
                else{arr[i][x-1]=2;}//if take and reject both wish for same object
            }
        }

        memset(sol,0,m*sizeof(int));
        scanf("%d",&p);
        for(i=0;i<p;i++)
        {
            scanf("%d",&temp);
            sol[temp-1]=1;//if that object is in solution
        }

        given=true;
        printf("Case %d: ",++cas);
        for(i=0;i<n;i++)//checking if solution is ok, at least one of wish is fulfilled
        {
            wish=false;
            for(j=0;j<m;j++)
            {
                if(arr[i][j]<0 && sol[j]==0)//if ith person reject object j, and so in solution
                {
                    wish=true;
                    break;//no need of more checking, at least one wish is fulfilled
                }
                if(arr[i][j]==1 && sol[j]==1)//if ith person take object j, and so in solution
                {
                    wish=true;
                    break;
                }
                if(arr[i][j]==2)//both reject and take wish for same object
                {
                    wish=true;
                    break;
                }
            }
            if(!wish)//no wish is fulfilled
            {
                printf("No\n");
                given=false;//given solution is incorrect
                break;
            }
        }
        if(given)
        {
            printf("Yes\n");
        }
    }
    return 0;
}
