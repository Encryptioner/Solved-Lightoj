#include<bits/stdc++.h>//wrong answer though passed every known test case, runtime error
using namespace std;

#define MX 100005
vector<long long int>arr(MX),tree(4*MX);

void insert_update(long long int node,long long int b,long long int e,long long int pos,long long int value)
{
    if(b==pos & pos==e)
    {
        tree[node]+=value;
        return;
    }
    long long int l=node*2,r=l+1,mid=(b+e)/2;
    if(pos<=mid)
    {
        insert_update(l,b,mid,pos,value);
    }
    else
    {
        insert_update(r,mid+1,e,pos,value);
    }
    tree[node]=tree[l]+tree[r];
}

long long int query(long long int node,long long int b,long long int e,long long int i,long long int j)
{
    if(i==b && j==e)
    {
        return tree[node];
    }
    long long int l=node*2,r=l+1,mid=(b+e)/2;
    if(j<=mid)
    {
        return query(l,b,mid,i,j);
    }
    else if(i>mid)
    {
        return query(r,mid+1,e,i,j);
    }
    else
    {
        return query(l,b,mid,i,mid)+query(r,mid+1,e,mid+1,j);
    }
}

int main()
{
    //freopen("1112. Curous Robin Hood.txt","r",stdin);
    long long int t,sum,n,q,i,j,c=0,task,v,val;

    cin>>t;

    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            insert_update(1,1,n,i,arr[i]);
        }

        printf("Case %lld:\n",++c);
        while(q--)
        {
            scanf("%lld",&task);
            if(task==1)
            {
                scanf("%lld",&i);
                val=query(1,1,n,i+1,i+1);
                printf("%lld\n",val);
                insert_update(1,1,n,i+1,-val);
            }
            else if(task==2)
            {
                scanf("%lld %lld",&i,&v);
                insert_update(1,1,n,i+1,v);
            }
            else
            {
                scanf("%lld %lld",&i,&j);
                printf("%lld\n",query(1,1,n,i+1,j+1));
            }
        }
        arr.clear();
        tree.clear();
    }
    return 0;
}
