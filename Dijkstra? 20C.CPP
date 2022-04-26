#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

const int N = 1e5 + 4, M = 2*1e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f,intmax=1e18;

ll n, m;

ll head[N], to[M], nxt[M], cost[M],pass[N], ne;

void init(ll n)
{
    memset(head, -1, n*sizeof(head[0]));
    ne = 0;
}

void addEdge(ll f, ll t, ll c)
{
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(ll a, ll b, ll c)
{
    addEdge(a, b, c);
    addEdge(b, a, c);
}
ll endcost[N];
void dpass(ll node)
{
    if(node==-1) return;
    dpass(pass[node]);
    cout<<node+1<<" ";
}
void Dijkstra(ll src)
{

    fill(endcost,endcost+n,1e18);
    endcost[src]=0;
    priority_queue<pair<ll, ll>> pq;

    pq.push({-endcost[src],src});
    ll u,d;
    while(pq.size())
    {

         u=pq.top().s;
         d=-pq.top().f;
        pq.pop();

        if(d!=endcost[u])
            continue;
            ll v,c,nc;
        for(ll e = head[u]; ~e; e = nxt[e])
        {
            v=to[e];
             c=cost[e];
             nc=c+d;
            if(nc<endcost[v])
            {
                endcost[v]=nc;
                pq.push({-nc,v});
                pass[v]=u;
            }


        }
    }





}

int main()
{
    ll t;




    ll src,dist,u,v,c;
    cin>>n>>m;
    init(n);
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v>>c;
        addBiEdge(--u,--v,c);

    }
    pass[0]=-1;
    Dijkstra(0);

    if(endcost[n-1]==1e18)
        cout<<"-1"<<endl;
    else
        dpass(n-1);




    return 0;
}
