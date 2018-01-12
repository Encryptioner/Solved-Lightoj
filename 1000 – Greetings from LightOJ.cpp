#include <iostream>//Accepted
#include <cstdio>

using namespace std;

int main()
{
    int t,a,b,i;

    while(scanf("%d",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            cin>>a;
            cin>>b;

            cout<<"Case "<<i<<": "<<a+b<<endl;
        }

    }
    return 0;
}
