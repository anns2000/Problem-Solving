#include <bits/stdc++.h>

using namespace std;
int const N=1e5+5;
vector<int>adj[N];
bool vis[N];
bool good =true;


void BFS(int node)
{
    queue<int>q;
    q.push(node);

    while(q.size())
    {
        int cur= q.front();
        q.pop();
        vis[cur]=1;
        for(auto child:adj[cur])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                q.push(child);
            }
        }
    }
}

int n,m;
int main()
{

    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(int i=0; i<m; i++)
    {
        int v,u;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 6 5
    if(n!=m)
    {

        good=false;
    }
    else
    {

        BFS(1);

        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                good=false;
            }
        }
    }

    if(good)
        cout<<"FHTAGN!"<<endl;
    else
        cout<<"NO"<<endl;

}
