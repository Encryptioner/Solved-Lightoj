#include<bits/stdc++.h>//Accepted
#define lld long long int

using namespace std;

vector  <int> counter[100];
int data2[10002],N=1001,MAX=0;

int number_divisor()
{
    lld n,n1,i,j,l,nod,count1;

    for(j=1;j<N;j++)
    {
    nod=1;
    n=j;
    n1=n;
    l=sqrt(n);

    for(i=2;i<=l;i++)
    {
        count1=0;
        if(i>3)
        {
            i++;
        }
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
                count1++;
            }
        }
        nod*=(count1+1);
    }

    if(n1==n && n==1)
    {
        nod=1;
    }
    else if(n1==n)
    {
        nod=2;
    }
    else if(n1!=n && n!=1)
    {
        nod*=2;
    }
    counter[nod].push_back(j);
    if(nod>MAX)
    {
        MAX=nod;
    }
    }
    //cout<<"max = "<<MAX<<endl;
    return 0;
}
int Bubble_Sort_2()
{
    int i,j,k,l,x=1;

    for(i=1;i<=MAX;i++)
    {
        l=counter[i].size();

        for(j=1;j<l;j++)
        {
            for(k=l-1;k>=j;k--)
            {
                //cout<<l<<endl;
                if(counter[i][k-1]<counter[i][k])
                {
                    swap(counter[i][k-1],counter[i][k]);
                }
            }
        }
        for(j=0;j<l;j++)
        {
            data2[x]=counter[i][j];
            //cout<<x<<" "<<data2[x]<<", ";
            x++;
        }
    }
    return 0;
}

int main()
{
    //freopen("1109. False Ordering.txt","r",stdin);
    number_divisor();
    Bubble_Sort_2();

    int i,t,n,c=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",++c,data2[n]);
    }
    return 0;
}

