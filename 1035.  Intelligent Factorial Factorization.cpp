#include<bits/stdc++.h>//Accepted
using namespace std;

int prime_list[25]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int factors[101][101], counter[101][101] ;


int primeFactors(int num)
{
    int expo,prime,num1;
    num1=num;
    for (int i = 0; prime_list[i] <= sqrt(num); i++)
    {
        expo = 0;
        prime = prime_list[i];
        while (num % prime == 0)
        {
            expo++;
            num = num / prime;
        }
        if (expo>0)
        {
            //factors.push_back(make_pair(prime, expo));
            factors[num1][prime]=expo;
        }
    }
    if ( num >= 2)
    {
        //factors.push_back(make_pair(num, 1));
        factors[num1][num]=1;
    }
    return 0;

}
int countFactors()
{
    int i,j,x;

    for(i=2;i<=100;i++)
    {
        for(j=0;j<25;j++)
        {
            x=prime_list[j];
            if(x>i)
            {
                break;
            }
            counter[i][x]=counter[i-1][x] + factors[i][x];
            //cout<<i<<" "<<x<<" "<<counter[i][x]<<" "<<counter[i-1][x-1]<<" "<<factors[i][x]<<endl;
        }
    }
    return 0;
}
int main()
{
    int t,N,i,c=0,j,x;
    for(i=2;i<=100;i++)
    {
        primeFactors(i);
    }
    countFactors();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        if(N==1)
        {
            printf("Case %d: 1 = 1 (1)\n",++c);
            continue;
        }
        printf("Case %d: %d =",++c,N);
        for(j=0;j<25;j++)
        {
            x=prime_list[j];

            if(counter[N][x]>0)
            {
                if(j!=0)
                {
                    printf(" *");
                }
                printf(" %d (%d)",x,counter[N][x]);
            }
        }
        printf("\n");
    }
    return 0;
}
