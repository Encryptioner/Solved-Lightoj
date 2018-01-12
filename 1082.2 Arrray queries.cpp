#include<bits/stdc++.h>//Accepted

using namespace std;

#define MX 100001
vector<int>arr(MX),tree(4*MX);

void insert_update(int node, int b, int e, int pos, int value)
{
cout<<node<<" "<<b<<" "<<e<<" "<<pos<<" "<<value<<" function\n";
    if(b == pos && pos == e)
    {
        tree[node] = value;
        cout<<" return\n";
        return;
    }

    int l = node*2;
    int r = l + 1;
    int mid = (b+e)/2;
cout<<l<<" "<<r<<" "<<mid<<" print\n\n";
    if(pos <= mid)
    {
        insert_update(l, b, mid, pos, value);
    }
    else
    {
        insert_update(r, mid+1, e, pos, value);
    }

    tree[node] = min(tree[l] , tree[r]);
    cout<<node<<" "<<l<<r<<" "<<tree[l]<<" "<<tree[r]<<" "<<tree[node]<<endl;
}


int query(int node, int b, int e, int i, int j)
{
cout<<node<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<" function\n";
    if(i==b && j==e)
    {
        cout<<" return\n";
        return tree[node];
    }

    int l = node*2;
    int r = l + 1;
    int mid = (b+e)/2;

cout<<l<<" "<<r<<" "<<mid<<" print\n\n";
    if(j<=mid)
    {
        return query(l, b, mid, i, j);
    }
    else if(i > mid)
    {
        return query(r, mid+1, e, i, j);
    }
    else
    {
cout<<" both\n";
        int x=query(l, b, mid, i, mid);
cout<<" both (l, b, mid, i, mid) "<<x<<endl;
        int y=query(r, mid+1, e, mid+1, j);
cout<<" both (r, mid+1, e, mid+1, j) "<<y<<endl;
        return min(x,y);
    }
}

int main()
{
    int t,N,q,i,x,y,c=0,minimum;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&N,&q);

        for(i=1;i<=N;i++)
        {
            scanf("%d",&arr[i]);
            insert_update(1, 1, N, i, arr[i]);
        }
        printf("Case %d:\n",++c);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            minimum=query(1,1,N,x,y);
            printf("%d\n",minimum);
        }
        arr.clear();
        tree.clear();
    }
    return 0;
}
