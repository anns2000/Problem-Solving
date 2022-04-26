#include <bits/stdc++.h>
#define ll long long
const int INTMAX((int)1e6);
using namespace std;

int par[INTMAX], cnt[INTMAX];

void init(int n)
{
    iota(par, par + n, 0);
    fill(cnt, cnt + n, 1);
}
int findParent(int u)
{
    if (u == par[u])
        return u;
    return par[u] = findParent(par[u]);
}
void join(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (u != v)
    {
        if (cnt[u] > cnt[v])
            swap(u, v);
        par[u] = v;
        cnt[v] += cnt[u];
    }
}
priority_queue<pair<ll, pair<int, int>>> edges;
void cases();
ll MST()
{
    ll ret = 0;
    while (edges.size())
    {
        auto e = edges.top();
        edges.pop();
        int u = e.second.first;
        int v = e.second.second;
        int c = -e.first;
       if(findParent(u) != findParent(v)){
        //cout<<u<<"  "<<v<<"  "<<c<<endl;
            join(u, v);
            ret += c;
        }
    }
    return ret;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        cases();

    return 0;
}
void cases()
{
    string name;
    int n, x, v, c;
    cin >> n;
    init(n);
    for (int u = 0; u < n; u++)
    {
        cin >> name >> x;
        for (int i = 0; i < x; i++)
        {
            cin >> v >> c;
            edges.push({-c, {u, --v}});
        }
    }
    cout<<MST()<<endl;
}
