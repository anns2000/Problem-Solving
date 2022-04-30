#include <bits/stdc++.h>

using namespace std;
int const N=510;
vector<int>adj[N];
int n,m,k;
int vis[N][N];

int movex[5]= {1,0,-1,0};
int movey[5]= {0,1,0,-1};

void init()
{

}

int cnt=0;

void BFS(int x,int y)
{
    queue<pair<int,int>>q;
    cnt-=k;
    q.push({x,y});
    cnt--;
    vis[x][y]=2;

    while(q.size())
    {
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();
        // cout<<curx<<" "<<cury<<endl;
        for(int i=0;i<4;i++)
        {
            int nx=movex[i]+curx;
            int ny=movey[i]+cury;
            //cout<<"try x "<<nx<<" try y "<<ny<<endl;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0&&cnt)
            {
                //cout<<nx<<"  now  "<<ny<<endl;
                cnt--;
                vis[nx][ny]=2;
                q.push({nx,ny});
            }
        }
    }
}


int main()
{

    cin>>n>>m>>k;

    for(int i=1; i<=n; i++)
    {
         for(int j=1; j<=m; j++)
         {
            char o;
            cin>>o;
            if(o=='#')
                vis[i][j]=1;
            else
            {
                vis[i][j]=0;
                cnt++;
            }
         }

    }



    bool ans=false;
     for(int i=1; i<=n; i++)
    {
         for(int j=1; j<=m; j++)
         {
             if(vis[i][j]==0&&!ans)
             {
                 BFS(i,j);
                 ans=true;
             }
         }
    }


    for(int i=1;i<=n; i++)
    {
         for(int j=1;j<=m;j++)
         {
             if(vis[i][j]==0)
                cout<<'X';
             else if(vis[i][j]==1)
             cout<<'#';
            else if(vis[i][j]==2)
                cout<<'.';
         }
         cout<<endl;
    }




}
