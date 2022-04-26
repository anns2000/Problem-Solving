#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
const int INTMAX((int)110);
using namespace std;

int par[INTMAX], cnt[INTMAX],compu;
priority_queue<pair<ll, pair<int, int>>> pq;

void init(int n)
{
    iota(par, par + n, 0);
    fill(cnt, cnt + n, 1);
    compu=n;
}
int findParent(int u)
{
    if (u == par[u])
        return u;
    return par[u] = findParent(par[u]);
}
bool join(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (u != v)
    {
        if (cnt[u] > cnt[v])
            swap(u, v);
        par[u] = v;
        cnt[v] += cnt[u];
        return true;
    }
return false;
}

int xarr[105],yarr[105];
int mst()
{

}
int main()
{
int n,f,t;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>xarr[i]>>yarr[i];

}
init(n);
for(int i=0;i<n;i++)
{
    for(int j=0;j<i;j++)
    {
        if(xarr[i]==xarr[j]||yarr[i]==yarr[j])
              compu-=join(i,j);
    }
}
cout<<compu-1<<endl;

}
