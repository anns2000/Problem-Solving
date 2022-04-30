#include <bits/stdc++.h>

using namespace std;
int const N=1e5+5;
vector<int>adj[N];
int vis[N];
int cnt=0,pos=1;

void init()
{
    memset(vis,0,sizeof(vis));
    cnt=0,pos=0;
}
void BFS(int node)
{
   queue<int>q;
   //cout<<"node = "<<node<<" "<<vis[node]<<endl;
   vis[node]=1;
 //cout<<"node = "<<node<<" "<<vis[node]<<endl;
   q.push(node);

   while(q.size())
   {
       int cur=q.front();
       q.pop();
       for(auto child:adj[cur])
       {
           if(vis[child]==0)
           {
               //cout<<child<<" "<<cur<<endl;
               vis[child]=vis[cur]+1;
               if(cnt<vis[child])
               {
                   cnt=vis[child];
                    pos=child;
               }
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

   BFS(1);
    int x=pos;
    init();
    BFS(x);
    cout<<cnt-1<<endl;


}
