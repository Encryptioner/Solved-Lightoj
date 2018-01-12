#include<bits/stdc++.h>//Accepted
#define lld  unsigned long long int

using namespace std;

int main()
{
    freopen("1053. Higher Math.txt","r",stdin);
    lld t,a,b,c,A,B,C,k=0;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld %lld",&A,&B,&C);
        c=max( max(A,B) , C );
        a=min( min(A,B) , C );

        if(A!=a && A!=c)
        {
            b=A;
        }
        else if(B!=a && B!=c)
        {
            b=B;
        }
        else
        {
            b=C;
        }
        printf("Case %lld: ",++k);
        //cout<<a<<" "<<b<<" "<<c<<" ";
        if( ((a*a)+(b*b)) == (c*c) )
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
