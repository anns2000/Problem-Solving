#include <bits/stdc++.h>

using namespace std;
int const N=1e4+5;
int vis[N];
vector<int>adj[N],path;

int n,m,cnt,out;
void init()
{
    memset(vis, 0, sizeof(vis));
    for( int i=1; i<=n; i++)
    {
        adj[i].clear();
    }
    path.clear();
    cnt=0;
    out=0;
}
void add(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int node)
{
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(vis[child]==0)
        {
            DFS(child);
            cnt++;
        }
    }

}
int main()
{
    cin>>n>>m;

        init();
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
        }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            DFS(i);
        out+=cnt;
        }

    }
    long long lol=1;
   while(cnt--)
   {
       lol*=2;
   }
cout<<lol<<endl;

}
