#include<bits/stdc++.h>//Accepted
using namespace std;

bool leap(int y)
{
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0){return true;}
            else{return false;}
        }
        else{return true;}
    }
    else{return false;}
}
int incentury(int y1,int y2)
{
            int x=0,y=0,ans=0;
            if(leap(y1)){x=1;}
            if(leap(y2)){y=1;}
            if(y1==y2 && x==1)
            {
                ans=1;
                return ans;
            }
            y1+=1;y2-=1;
            if(y2<y1)
            {
                ans=x+y;
                return ans;
            }
            if(y1==y2)
            {
                if(leap(y2)){ans=1;}
                else{ans=0;}
                return ans;
            }
            if((int)(y1/100)==(int)(y2/100))
            {
                if(leap(y1)){x=1;y1+=1;}
                if(!leap(y1)){y1+=4-(y1%4);}
                if(!leap(y2)){y2-=(y2%4);}
                ans=(y2-y1)/4;
                ans+=1+x+y;
                return ans;
            }
}
int main()
{
    //freopen("1414. February 29.txt","r",stdin);
    int t,cas=0,d1,d2,y1,y2,x,y,leap1,leap2,ans,cy1,cy2,ans1,ans2,ans3,cen,lcen;


    scanf("%d",&t);
    while(t--)
    {
        string m1,m2,c;
        x=0,y=0,leap1=0,leap2=0,ans=0;
        cin>>m1>>d1>>c>>y1;
        cin>>m2>>d2>>c>>y2;

        if( (m1=="January" || m1=="February") && leap(y1)==true){x=1;}
        if( (m2!="January" && m2!="February") && leap(y2)==true){y=1;}
        if( m2=="February" && d2==29 && leap(y2)==true){y=1;}
        while(1)
        {
            if(y1==y2)
            {
                if(x==1 && y==1){ans=1;}
                else{ans=0;}
                break;
            }
            y1+=1;y2-=1;

            if(y2<y1)
            {
                ans=x+y;
                break;
            }
            if(y1==y2)
            {
                if(leap(y2)){ans=1;}
                else{ans=0;}
                break;
            }
            if((int)(y1/100)==(int)(y2/100))//in same century
            {
                if(leap(y1)){x=1;y1+=1;}
                if(!leap(y1)){y1+=4-(y1%4);}
                if(!leap(y2)){y2-=(y2%4);}
                ans=(y2-y1)/4;
                ans+=1+x+y;
                break;
            }
            else
            {
                if(y1%100==0 && y1%400==0){x=1;y1+=1;}
                if(y2%100==0 && y2%400==0){y=1;y2-=1;}
                cy1=y1/100;cy1=cy1*100+100;
                cy2=y2/100;cy2=cy2*100;
                //cout<<y1<<" "<<y2<<" "<<cy1<<" "<<cy2<<endl;
                ans1=incentury(y1,cy1-1);
                ans3=incentury(cy2+1,y2);
                //cout<<y1<<" "<<y2<<" "<<cy1<<" "<<cy2<<" "<<ans1<<" "<<ans3<<" "<<x<<" "<<y<<endl;
                cen=(cy2-cy1)/100;
                if(!leap(cy1)){cy1+=400-(cy1%400);}
                if(!leap(cy2)){cy2-=(cy2%400);}
                lcen=(cy2-cy1)/400+1;
                ans2=cen*24+lcen+x+y;
                ans=ans1+ans2+ans3;
                //cout<<cy1<<" "<<cy2<<" "<<cen<<" "<<lcen<<" "<<ans2<<endl;
                break;
            }
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
