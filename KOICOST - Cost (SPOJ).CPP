#include <bits/stdc++.h>
#define S second
#define F first

using namespace std;

const int N = 1e5 + 5, M = 2 * N, mod = 1e9;

typedef long long ll;

int n, par[N], cnt[N];
vector<pair<int, pair<int, int> > > edges;

int getParent(int u)
{
	if(par[u] == u) return u;
	return par[u] = getParent(par[u]);
}

bool connect(int u, int v)
{
	u = getParent(u);
	v = getParent(v);
	if(u == v) return false;
	if(cnt[u] < cnt[v]) swap(u, v);
	par[v] = u;
	cnt[u] += cnt[v];
	return true;
}

ll mst()
{
	ll ret = 0, ans = 0;
	iota(par, par + n, 0);
	fill(cnt, cnt + n, 1);
	sort(edges.rbegin(), edges.rend());
	for(auto &e:edges)
	{
		int u = getParent(e.S.F), v = getParent(e.S.S);
		if(u != v)
		{
			ans += 1LL * cnt[u] * cnt[v];
			connect(u, v);
		}
		ret = (ret + ((ans * e.F) % mod)) % mod;
	}
	return ret;
}

int main()
{
//	freopen("input.in", "rt", stdin);
	int m, u, v, c;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v>>c;
		edges.emplace_back(c, make_pair(--u, --v));
	}
	cout<<mst()<<endl;
	return 0;
}
