#include<bits/stdc++.h>//Accepted
using namespace std;
 
#define MX 100009
#define lld long long int

vector<lld>arr(MX),tree(4*MX);
 
void insert_update(lld node,lld b,lld e,lld pos,lld value)
{
//cout<<node<<" "<<b<<" "<<e<<" "<<pos<<" "<<value<<" function\n";
    if(b==pos && pos==e)
    {
        tree[node]+=value;
        return;
    }
    lld l=node*2,r=l+1,mid=(b+e)/2;
//cout<<l<<" "<<r<<" "<<mid<<" print\n\n";
    if(pos<=mid)
    {
        insert_update(l,b,mid,pos,value);
    }
    else
    {
        insert_update(r,mid+1,e,pos,value);
    }
    tree[node]=tree[l]+tree[r];
//cout<<node<<" "<<l<<r<<" "<<tree[l]<<" "<<tree[r]<<" "<<tree[node]<<endl;
}
 
lld query(lld node,lld b,lld e,lld i,lld j)
{
//cout<<node<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<" function2\n";
    if(i==b && j==e)
    {
        return tree[node];
    }
    lld l=node*2,r=l+1,mid=(b+e)/2;
//cout<<l<<" "<<r<<" "<<mid<<" print\n\n";
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
        //cout<<" both\n";
        int x=query(l,b,mid,i,mid);
        //cout<<" both (l, b, mid, i, mid) "<<x<<endl;
        int y=query(r,mid+1,e,mid+1,j);
        //cout<<" both (r, mid+1, e, mid+1, j) "<<y<<endl;
        return x+y;
    }
}
 
int main()
{
    //freopen("1112. Curous Robin Hood.txt","r",stdin);
    //freopen("1112. Curous Robin Hood_o.txt","w",stdout);
    
    lld t,n,q,i,j,c=0,task,v,val;
 
    cin>>t;
 
    while(t--)
    {
//cout<<"\n\n\n New\n\n\n";
        scanf("%lld %lld",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i+1]);
            insert_update(1,1,n,i+1,arr[i+1]);
        }
 
        printf("Case %lld:\n",++c);
        while(q--)
        {
            scanf("%lld",&task);
            //cout<<task<<" tsk\n";
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
        for(i=0;i<=4*MX;i++)
        {
			tree[i]=0;
		}
    }
    return 0;
}
 
