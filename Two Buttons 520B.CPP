#include <bits/stdc++.h>

using namespace std;
// USING BFS
int const N=1e4+10;
 int x,y;
int vis[N];


void BFS(int x)
{
    vis[x]=0;
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int cur=q.front();
        q.pop();
        if(cur==y)
            return ;

        int try1=cur*2;
        int try2=cur-1;

        if(try1<2*y&&vis[try1]==-1)
        {
            vis[try1]=vis[cur]+1;
            q.push(try1);
        }
        if(try2>0&&vis[try2]==-1)
        {
            vis[try2]=vis[cur]+1;
            q.push(try2);
        }
    }
}


int main()
{

  memset(vis,-1,sizeof(vis));

   cin>>x>>y;
   BFS(x);
   cout<<vis[y]<<endl;
    return 0;
}
