#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#define ll long long
const int INTMAX((int)1e5 + 10);
using namespace std;
set<pair<int, int>> in;
int par[INTMAX], countComp;
vector<int> adj[INTMAX];
void init(int n)
{
    iota(par, par + n + 1, 0);
    countComp = n;
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
        par[u] = v;
        countComp--;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    init(n);
    int from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    set<int> st;

    for (int i = 1; i <= n; i++)
        st.insert(i);
    for (int i = 1; i <= n; i++)
    {
        for (int x : adj[i])
            st.erase(x);

        for (int x : st)
            join(i, x);

        st.clear();
        st.insert(i);
        for (int x : adj[i])
            st.insert(x);
    }

    cout << countComp - 1 << endl;
    return 0;
}
