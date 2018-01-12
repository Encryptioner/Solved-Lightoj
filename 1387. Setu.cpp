#include<bits/stdc++.h>//Accepted
#define lld long long int
using namespace std;

int main()
{
    lld k,t,c=0,sum,n;
    string s;
    scanf("%lld",&t);
    while(t--)
    {
        printf("Case %lld:\n",++c);
        sum=0;
        scanf("%lld",&n);
        while(n--)
        {
            cin>>s;
            if(s[0]=='r')//if report print
            {
                printf("%lld\n",sum);
            }
            else//increase value of sum
            {
                scanf("%lld",&k);
                sum+=k;
            }
        }
    }
    return 0;
}
