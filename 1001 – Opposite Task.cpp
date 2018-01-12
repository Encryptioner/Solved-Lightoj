#include <iostream>//accepted
#include <cstdio>

using namespace std;

int main()
{
    int t,n,x,i,p,q;
    x=1;
    p=9;
    q=1;
    while(scanf("%d",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            cin>>n;

            if(n!=x)
            {
                p=9;
                q=1;
            }

            if(n!=x && n>10 && n<=20)
            {
                cout<<n-10<<" "<<10<<endl;
            }
            else if(n!=x && n>=0 && n<=10)
            {
                cout<<0<<" "<<n<<endl;
            }
            else if(n==x && n>10 && n<20)
            {
                cout<<n-p<<" "<<p<<endl;
                if(n-p<10)
                {
                    p--;
                }
            }
            else if(n==x && n==20)
            {
                cout<<10<<" "<<10<<endl;
            }
            else if(n==x && n>0 && n<10)
            {
                cout<<q<<" "<<n-q<<endl;
                if(q<n)
                {
                    q++;
                }
            }
            else if(n==x && n==10)
            {
                cout<<q<<" "<<10-q<<endl;
            }
            else if(n==x && n==0)
            {
                cout<<0<<" "<<0<<endl;
            }

            x=n;
        }
    }
    return 0;
}
