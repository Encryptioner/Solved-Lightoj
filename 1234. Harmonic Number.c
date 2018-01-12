#include<stdio.h>//Accepted
#include<math.h>
#define lld long long int

double arr[100001];
int main()
{
    //freopen("1234. Harmonic Number.txt","r",stdin);
    lld i,t,cas=0,n,x=0,c;
    double val=1.50,s;
    for(i=3;i<=100000000;i+=2)
    {
        s=(2+pow(i,-1))/(i+1);
        val+=s;

        if((i+1)%1000==0)
        {
            arr[++x]=val;
            //printf("x %lld %lld %.10lf\n",i+1,x,arr[x]);
        }
    }

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        x=n/1000;
        c=n%1000;
        val=arr[x];
        //cout<<n<<" "<<val<<endl;
        for(i=1;i<=c;i++)
        {
            val+=pow(x*1000+i,-1);
        }
        printf("Case %lld: %.10lf\n",++cas,val);
    }
    return 0;
}
