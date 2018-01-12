#include <bits/stdc++.h>//Accepted
using namespace std;

typedef pair< int, int > pii;
typedef pair< pii, int > pii2;

const int MAX = 10001;
const int INF = 0x3f3f3f3f;

vector< pii2 > G[MAX];
int d[MAX][11];

int dijkstra(int node, int max_new)
{
	int u, v, c, w, x, y, gus, i, j, k, ret = INF;
	int src=0,destination=node-1;
	priority_queue< pii2, vector< pii2 >, greater< pii2 > > Q;

	memset(d, 0x3f, sizeof d);
	d[src][0] = 0;
	Q.push(pii2(pii(d[src][0], 0), src));

	while(!Q.empty()) {
		u = Q.top().second;
		c = Q.top().first.first;
		x = Q.top().first.second;
		Q.pop();
		if(d[u][x] < c)
        {
            continue;
        }
		gus = G[u].size();
		for(i = 0; i < gus; i++)
        {
			v = G[u][i].second;
			w = G[u][i].first.first;
			y = G[u][i].first.second;
			if(x + y > max_new)
			{
                continue;
            }
			if(d[u][x] + w < d[v][x+y])
            {
				d[v][x+y] = d[u][x] + w;
				Q.push(pii2(pii(d[v][x+y], x+y), v));
			}
		}
	}
	for(i = 0; i <= max_new; i++)
    {
        ret = min(ret, d[destination][i]);
    }
	return ret;
}

int main()
{
    freopen("1281.  New Traffic System .txt","r",stdin);
	int T,c=0, i,j,k, node1, node2, cost, ret, node,pre_road,new_road,max_new;

	cin>>T;
	while(T--){
		scanf("%d %d %d %d", &node, &pre_road, &new_road, &max_new);
		for(i = 0; i < node; i++)
        {
            G[i].clear();
        }
		for(i = 0; i < pre_road; i++)
        {
			scanf("%d %d %d", &node1, &node2, &cost);
			G[node1].push_back(pii2(pii(cost, 0), node2));
		}
		for(i = 0; i < new_road; i++)
		{
			scanf("%d %d %d", &node1, &node2, &cost);
			G[node1].push_back(pii2(pii(cost, 1), node2));
		}
		ret = dijkstra(node,max_new);
		if(ret == INF)
		{
		    printf("Case %d: Impossible\n", ++c);
		}
		else
        {
            printf("Case %d: %d\n", ++c, ret);
        }
	}
	return 0;
}
