#include <bits/stdc++.h>
#define s second
#define f first
#define ll long long

using namespace std;

const int N = 2e5 + 5, M = 2 * N;
int n, par[N],cnt[N];
void init(int n)
{
    iota(par, par + n, 0);
    fill(cnt, cnt+ n, 1);

}

int getParent(int u)
{
    if(par[u] == u) return u;
    return par[u] = getParent(par[u]);
}
bool check(int u, int v)
{
    u = getParent(u);
    v = getParent(v);
    if(u == v)
        return false;

    return true;
}
void connect( int u, int v)
{
    u = getParent(u);
    v = getParent(v);
    if(u!=v)
    {
    cnt[u]+=cnt[v];
    par[v] = u;
    }

}


int t=0;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        init(n);
        for(int i=0; i<n; i++)
        {
//1 2 3 4 5
            int x;
            cin>>x;
            // cout<<i<<" "<<--x<<endl;
            connect(i,--x);
        }
/*20
5 1 6 19 14 3 20 10 9 15 4 7 2 8 17 13 12 18 16 11*/
        for(int i=0; i<n; i++)
        {
            cout<<cnt[getParent(i)]<<" ";
        }
cout<<endl;
    }

    return 0;
}
