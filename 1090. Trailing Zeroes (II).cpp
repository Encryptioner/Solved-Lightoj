#include<bits/stdc++.h>//Accepted
using namespace std;

int main()
{
    //freopen("1090. Trailing Zeroes (II).txt","r",stdin);
    int n,r,p,q,t,x,y,z,count1,count2,count22,count3,count5,count,c=0,i;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d %d",&n,&r,&p,&q);
        count1=0;
        count2=0;
        count3=0;

        for(i=1; ;i++)
        {
            x=n/pow(5,i);
            y=(n-r)/pow(5,i);
            z=r/pow(5,i);

            count1+=x;
            count2+=y;
            count3+=z;

            if(x==0 && y==0 && z==0)
            {
                break;
            }
        }
        cout<<"Number of 5 = "<<count1<<endl;
        count5=count1-count2-count3;
        //cout<<"5th "<<count1<<" "<<count2<<" "<<count3<<" "<<count5<<endl;
        count1=0;
        count2=0;
        count3=0;
        for(i=1; ;i++)
        {
            x=n/pow(2,i);
            y=(n-r)/pow(2,i);
            z=r/pow(2,i);

            count1+=x;
            count2+=y;
            count3+=z;

            if(x==0 && y==0 && z==0)
            {
                break;
            }
        }
        count22=count1-count2-count3;
        //cout<<"2th "<<count1<<" "<<count2<<" "<<count3<<" "<<count22<<endl;
        x=0;
        y=0;
        if( (p%2) == 0 )
        {
            while( (p%2) == 0 )
            {
                p=p/2;
                x++;
            }
        }
        if( (p%3) == 0 )
        {
            while( (p%3) == 0 )
            {
                p=p/3;
            }
        }
        if( (p%5) == 0 )
        {
            while( (p%5) == 0 )
            {
                p=p/5;
                y++;
            }
        }
        count22+=x*q;
        count5+=y*q;

        count=min(count22,count5);

        //cout<<"fin "<<count22<<" "<<count2<<" "<<x*q<<" "<<y*q<<endl;
        printf("Case %d: %d\n",++c,count);
    }
    return 0;
}
