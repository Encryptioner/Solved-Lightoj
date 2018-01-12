#include <iostream>//Accepted
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int a,b,c,d;
    int w,x,y,z,w1,x1,y1,z1,r,s,u,v;
    string m,n;
    int i,j,k,t,p1,p2;

    //freopen("1354. IP checking.txt","r",stdin);
    //freopen("1354. IP checking_o.txt","w",stdout);
    while(cin>>t)
    {
        for(i=1;i<=t;i++)
        {
            cin>>m;
            cin>>n;
            a=b=c=d=w=x=y=z=p1=p2=r=s=u=v=0;
            w1=x1=y1=z1=-1;
            for(j=0;j<m.length();j++)
            {
                if(m[j]=='.')
                {
                    p1++;
                    j++;
                }
                if(p1==0)
                {
                    a=(a*10)+(m[j]-'0');
                }
                else if(p1==1)
                {
                    b=(b*10)+(m[j]-'0');
                }
                else if(p1==2)
                {
                    c=(c*10)+(m[j]-'0');
                }
                else if(p1==3)
                {
                    d=(d*10)+(m[j]-'0');
                }
            }
            //cout<<a<<"."<<b<<"."<<c<<"."<<d<<endl;
            for(k=0;k<n.length();k++)
            {
                if(n[k]=='.')
                {
                    p2++;
                    k++;
                }
                if(p2==0)
                {
                    w=(w*10)+(n[k]-'0');
                    w1++;
                }
                else if(p2==1)
                {
                    x=(x*10)+(n[k]-'0');
                    x1++;
                }
                else if(p2==2)
                {
                    y=(y*10)+(n[k]-'0');
                    y1++;
                }
                else if(p2==3)
                {
                    z=(z*10)+(n[k]-'0');
                    z1++;
                }
            }
            //cout<<w<<"."<<x<<"."<<y<<"."<<z<<endl;
            p1=p2=0;
            for(k=0;k<n.length();k++)
            {
                if(n[k]=='.')
                {
                    p2++;
                    k++;
                }
                if(p2==0)
                {
                    r=r+(n[k]-'0')*pow(2,w1);
                    w1--;
                }
                else if(p2==1)
                {
                    //cout<<"x1 = "<<x1<<endl;
                    s=s+(n[k]-'0')*pow(2,x1);
                    x1--;
                }
                else if(p2==2)
                {
                    u=u+(n[k]-'0')*pow(2,y1);
                    y1--;
                }
                else if(p2==3)
                {
                    v=v+(n[k]-'0')*pow(2,z1);
                    z1--;
                }
            }
            //cout<<r<<"  "<<s<<"  "<<u<<"  "<<v<<endl;
            if(a==r && b==s && c==u && d==v)
            {
                cout<<"Case "<<i<<": Yes"<<endl;
            }
            else
            {
                cout<<"Case "<<i<<": No"<<endl;
            }
        }
    }
    //printf("Written in file\n");
    return 0;

}
