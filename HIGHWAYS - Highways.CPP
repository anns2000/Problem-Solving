#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

const int N = 1e5 + 4, M = 2*1e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f,intmax=INT_MAX;

int n, m;

int head[N], to[M], nxt[M], cost[M], ne;

void init()
{
    memset(head, -1, sizeof head);
    ne = 0;
}

void addEdge(int f, int t, int c)
{
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int a, int b, int c)
{
    addEdge(a, b, c);
    addEdge(b, a, c);
}
int endcost[N];

void Dijkstra(int src)
{

    fill(endcost,endcost+n,intmax);
    endcost[src]=0;
    priority_queue<pair<int, int>> pq;

    pq.push({-endcost[src],src});

    while(pq.size())
    {

        int u=pq.top().s;
        int d=-pq.top().f;
        pq.pop();

        if(d!=endcost[u])
            continue;

        for(int e = head[u]; ~e; e = nxt[e])
        {
            int v=to[e];
            int c=cost[e];
            int nc=c+d;
            if(nc<endcost[v])
            {
                endcost[v]=nc;
                pq.push({-nc,v});
            }


        }
    }





}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        init();
        int src,dist,u,v,c;
        cin>>n>>m>>src>>dist;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>c;
            addBiEdge(--u,--v,c);

        }
        Dijkstra(--src);
        if(endcost[dist-1]==intmax)
            cout<<"NONE"<<endl;
        else
            cout<<endcost[dist-1]<<endl;
    }



    return 0;
}
