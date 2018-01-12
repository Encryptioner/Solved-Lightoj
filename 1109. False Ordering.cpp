#include<bits/stdc++.h>
#define lld long long int

using namespace std;

vector  <int> counter[100];
int divisor[1001],data[10001],data2[10001],N=1000,MAX=0;

int number_divisor()
{
    lld n,n1,i,j,l,nod,count1;

    for(j=0;j<N;j++)
    {
    nod=1;
    n=j+2;//1 ke exceptional dhore tar por theke hishab kora hoyese ekhane and bubble sort
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

    if(n1!=n)
    {
        nod*=2;
    }
    //cout<<"\nnod = "<<nod<<endl;
    divisor[j]=nod;
    data[j]=j+2;
    counter[nod].push_back(j+2);
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
    int i,j,k,l,x=2;
    for(i=1;i<=MAX;i++)
    {
        l=counter[i].size();
        cout<<l<<endl;
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
            cout<<l<<endl;
        }
    }
    for(i=1;i<=MAX;i++)
    {
        l=counter[i].size();
        for(j=1;j<l;j++)
        {
            data2[x]=counter[i][j];
            x++;
        }
    }
}
int Bubble_Sort()
{
    int i,j;

    for(i=1;i<N-1;i++)
    {
        for(j=N-2;j>=i;j--)
        {

            if(divisor[j-1]==divisor[j] && data[j-1]<data[j])
            {
                swap(divisor[j-1],divisor[j]);
                swap(data[j-1],data[j]);
            }
            else if(divisor[j-1]>divisor[j])//sorting in ascending orde
            {
                swap(divisor[j-1],divisor[j]);
                swap(data[j-1],data[j]);
            }
            else
            {

            }
        }
    }
    return 0;
}
int main()
{
    //freopen("1109. False Ordering.txt","r",stdin);
    number_divisor();
    //Bubble_Sort();
    Bubble_Sort_2();
    int i,t,n,c=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("Case %d: %d\n",++c,n);
        }
        else
        {
            //printf("Case %d: %d\n",++c,data[n-2]);
            printf("Case %d: %d\n",++c,data2[n]);
        }
    }
    return 0;
}




