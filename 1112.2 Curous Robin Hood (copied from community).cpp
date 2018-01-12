 /*
    #include <bits/stdc++.h>//Gives TLE
    using namespace std;
    typedef long long ll;
    const int N = 1e5;  // limit for array size
    int n;  // array size
    int t[2 * N];

    void build() {  // build the tree
      for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
    }

    void modify(int p, int value) {  // set value at position p
      for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }

    int query(int l, int r) {  // sum on interval [l, r)
      int res = 0;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
      }
      return res;
    }

    int main() {
        int t1,q,t2=0;
        cin>>t1;
        while(t1--)
        {
            printf("Case %d:\n",++t2);
            scanf("%d %d", &n,&q);
            for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
            build();
            while(q--)
            {
                int a;
                cin>>a;
                if(a==1)
                {
                    int z;
                    cin>>z;
                    int s=query(0,z+1)-query(0,z);
                    printf("%d\n",s);
                    modify(z,0);
                }
                else if(a==2)
                {
                    int z,y;
                    cin>>z>>y;
                    int s=query(0,z+1)-query(0,z);
                    modify(z,s+y);
                }
                else
                {
                    int p,q;
                    cin>>p>>q;
                    printf("%d\n",query(p,q+1));
                }
            }
        }


      return 0;
    }

*/

///*


    #include <bits/stdc++.h>//http://uvalightoj.blogspot.com/2015/06/lightoj-1112-curious-robin-hood.html
    #define C 100003
    using namespace std;

    int Sack[C], Tree[C*3];

    void build(int b, int e, int node){
        if(b >= e){
            if(b == e)Tree[node] = Sack[b];
            return;
        }
        int mid = (b+e) >> 1, internal1 = (node << 1), internal2 = internal1+1;
        build(b, mid, internal1);
        build(mid+1, e, internal2);
        Tree[node] = Tree[internal1] + Tree[internal2];
    }

    void update(int b, int e, int node, int I){
        if(b > I || e < I)return;
        if(b >= e){
            if(b == e)Tree[node] = Sack[b];
            return;
        }
        int mid = (b+e) >> 1, internal1 = (node << 1), internal2 = internal1+1;
        update(b, mid, internal1, I);
        update(mid+1, e, internal2, I);
        Tree[node] = Tree[internal1] + Tree[internal2];
    }

    int query(int b, int e, int node, int I, int J){
        if(b >= I && e <= J)return Tree[node];
        if(b > J || e < I)return 0;
        if(b > e)return 0;
        int mid = (b+e) >> 1, internal1 = (node << 1), internal2 = internal1+1;
        int x = query(b, mid, internal1, I, J);
        int y = query(mid+1, e, internal2, I, J);
        return x+y;
    }

    int main(){
        //freopen("1112. Curous Robin Hood.txt","r",stdin);
        int T, I, J, V, N, Q, F, CS = 0;
        scanf("%d", &T);
        while(T--){
            scanf("%d %d", &N, &Q);
            for(int i = 0; i < N; i++)scanf("%d", &Sack[i]);
            memset(Tree, 0, sizeof(Tree));
            build(0, N-1, 1);
            printf("Case %d:\n", ++CS);
            for(int i = 1; i <= Q; i++){
                scanf("%d", &F);
                if(F == 1){
                    scanf("%d", &I);
                    printf("%d\n", Sack[I]);
                    Sack[I] = 0;
                    update(0, N-1, 1, I);
        /*for(i=0;i<3*N;i++)
        {
            cout<<i<<" "<<Tree[i]<<endl;
        }*/
                }
                if(F == 2){
                    scanf("%d %d", &I, &V);
                    Sack[I] += V;
                    update(0, N-1, 1, I);
        for(i=0;i<3*N;i++)
        {
            cout<<i<<" "<<Tree[i]<<endl;
        }
                }
                if(F == 3){
                    scanf("%d %d", &I, &J);
                    printf("%d\n", query(0, N-1, 1, I, J));
                }
            }
        }
        return 0;
    }

//*/

/*
#include<bits/stdc++.h>//https://github.com/rafi-kamal/ACM-Solutions/blob/master/LightOj/Data%20Structures%20/1112%20-%20Curious%20Robin%20Hood.cpp
#define LongInt long long
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

#define BOUNDARY(i, j) (i < 0 || i > row-1 || j < 0 || j > column - 1)

#define SIZE 100005
#define digit(c) ((c) - '0')
#define PI 3.141592654
#define MAX_INT 2147483646
#define DIFF 10E-7
#define MOD 1000000007

using namespace std;

int f[SIZE];
int tree[SIZE];

int MaxIdx;

int read(int idx)
{
	int sum = 0;
	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

int update(int idx, int val)
{
	while(idx <= MaxIdx)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int query(int i, int j)
{
	return read(j) - read(i-1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	unsigned i, j, k, l, sum = 0;
	int tc, t, d, x, y, r, n, m, p, q,current, first;
	char ch;
	bool flag;

	scanf("%d", &tc);
	getchar();

	for(t = 1; t <= tc; t++)
	{
		scanf("%d %d", &n, &q);
		printf("Case %d:\n", t);
		MaxIdx = n;

		memset(tree, 0, sizeof tree);

		for(i = 1; i <= n; i++)
		{
			scanf("%d", &f[i]);
			update(i, f[i]);
		}

		for(i = 0; i < q; i++)
		{
			scanf("%d", &m);

			switch(m)
			{
				case 1:
					scanf("%d", &j); j++;
					update(j, -f[j]);
					printf("%d\n", f[j]);
					f[j] = 0;
					break;
				case 2:
					scanf("%d %d", &j, &k); j++;
					update(j, k);
					f[j] += k;
					break;
				case 3:
					scanf("%d %d", &j, &k); j++, k++;
					printf("%d\n", query(j, k));
					break;
			}
		}
	}

	return 0;
}
*/

