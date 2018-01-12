#include<stdio.h>//Accepted
#include<math.h>
#define MAX 1000003
double res[MAX];
int main()
{
    //freopen("1045. Digits of Factorial.txt","r",stdin);
    int n,t,b,c=0,i;
    double ans;

    res[0]=0.0;
    for(i=1;i<MAX;i++)
    {
        res[i]=res[i-1]+log(i);
    }

    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d",&n,&b);

        printf("Case %d: ",++c);
        if(n==0)
        {
            printf("1\n");
        }
        else
        {
        ans=res[n];
        ans/=log(b);

        printf("%.0lf\n",ceil(ans));
        }
    }
    return 0;
}
