#include <bits/stdc++.h>//Accepted
#define lld unsigned long long int
#define MAX 10001
using namespace std;

bool vis[MAX];
lld dp[MAX];

lld a, b, c, d, e, f;

lld fn( lld n )
{
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(vis[n]!=0)
    {
        return dp[n];
    }
    else
    {
        dp[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % 10000007;
        vis[n]=1;
        return dp[n];
    }
}

int main()
{
    freopen("1006. Hex-a-bonacci.txt","r",stdin);
    lld n, T , cases=0;

    scanf("%lld", &T);
    while( T-- )
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);

        printf("Case %lld: %lld\n", ++cases, fn(n)% 10000007);

        memset(vis,0,sizeof vis);
    }
    return 0;
}
//2^63 - 1 = 9223372036854775807.
