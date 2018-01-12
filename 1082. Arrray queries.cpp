#include<bits/stdc++.h>//not ok

using namespace std;

#define mx 100001
vector<long  long int>arr(mx),tree(mx*3);

void init(long long int node,long long int b,long long int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    long long int Left=node*2;
    long long int Right=node*2+1;
    long long int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    if(tree[Left]<tree[Right])
    {
        tree[node]=tree[Left];
    }
    else
    {
        tree[node]=tree[Right];
    }
}

long long int query(long long int node,long long int b,long long int e,long long int i,long long int j)
{
    cout<<node<<" "<<b<<" "<<e<<endl;
    if(i==b && j==e)
    {
        return tree[node];
    }
    long long int Left=node<<1;
    long long int Right=Left+1;
    long long int mid=(b+e)/2;

    if(j<=mid)
    {
        return query(Left,b,mid,i,j);
    }
    else if(i>mid)
    {
        return query(Right,mid+1,e,i,j);
    }
    else
    {
        return min(query(Left,b,mid,i,mid),query(Right,mid+1,e,mid+1,j));
    }
    //return tree[node];

    /*if (i > e || j < b)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<-1<<endl;
        return -1;
        //return 0;
    }
    if (b >= i && e <= j)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<tree[node]<<" initial"<<endl;
        return tree[node];
    }
    long long int Left=node*2;
    long long int Right=node*2+1;
    long long int mid=(b+e)/2;
    long long int p1=query(Left,b,mid,i,j);
    long long int p2=query(Right,mid+1,e,i,j);
    cout<<p1<<" "<<p2<<endl;
    if (p1 == -1)
    {
        return tree[node] = p2;
    }
    if (p2 == -1)
    {
        return tree[node] = p1;
    }
    if (arr[p1] <= arr[p2])
    {
        return tree[node] = p1;
    }
    return tree[node] = p2;
    //return min(p1,p2);*/
}

int main()
{
    long long int t,N,q,i,m,n,c=0,minimum;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&N,&q);

        for(i=1;i<=N;i++)
        {
            scanf("%lld",&arr[i]);
        }
        init(1,1,N);
        cout<<endl;
        for(i=0;i<=3*N;i++)
        {
            cout<<tree[i]<<" "<<i<<endl;
        }
        cout<<endl;
        printf("Case %lld:\n",++c);
        while(q--)
        {
            scanf("%lld %lld",&m,&n);
            minimum=query(1,1,N,m,n);
            printf("%lld\n",minimum);
        }
        arr.clear();
        tree.clear();
    }
    return 0;
}
