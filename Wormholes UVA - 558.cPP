#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m, edges_idx;

struct edge
{
    ll from, to, cost;
};

vector<edge> edges;

/// Time Complexity O(N * M), N = number of node & M = number of edges
ll dist[N];
bool bellman(ll src)
{
    for(ll i = 0; i < n; ++i)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for(ll i = 0; i < n; ++i)
    {
        bool stillRelaxing = 0;
        for(ll e = 0; e < edges.size(); ++e)
        {
            ll u = edges[e].from;
            ll v = edges[e].to;
            ll c = edges[e].cost;
            /// Can I relax using this edge?
            if(dist[u] + c < dist[v])
            {
                dist[v] = dist[u] + c;
                stillRelaxing = 1;
                if(i == n - 1)
                    return true;
            }
        }
        if(!stillRelaxing) break;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     edges.clear();
        cin >> n >> m;
        for(ll i = 0; i < m; ++i)
        {
            ll u, v, c;
            cin >> u >> v >> c;
            edges.push_back({u, v, c});

        }

        if(bellman(0))
        {
            cout <<"possible"<<endl;
        }
        else
        {
            cout <<"not possible"<<endl;
        }
    }

}

