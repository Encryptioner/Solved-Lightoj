#include <iostream>//Accepted
#include <cstdio>

using namespace std;

int main()
{
    int t,i;
    long long w,n,m;

    freopen("1116_1-input.txt","r",stdin);

    while(scanf("%d",&t)==1)
    {
        for(i=1;i<=t;i++)
        {

            cin>>w;

            if((w%2)!=0)
            {
                cout<<"Case "<<i<<": Impossible"<<endl;
            }
            else
            {
                for(m=2;m<=w/2;m=m+2)
                {
                    n=w/m;
                    if(n%2==1 && (m*n)==w)
                    {
                        cout<<"Case "<<i<<": "<<n<<" "<<m<<endl;
                        break;
                    }
                    if(m==w/2)
                    {
                        cout<<"Case "<<i<<": "<<1<<" "<<w<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
                /*m=w/2;
                for(n=1;n<m;n++)
                {
                    if((m*n==w))
                    {
                        cout<<"Case "<<i<<": "<<n<<" "<<m<<endl;
                        break;
                    }
                    else if(n==m-1)
                    {

                    }
                }*/
