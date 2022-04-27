#include <bits/stdc++.h>

using namespace std;

int const N=2e3+10;
int x,y,maxRow,maxCol;
int vis[N][N];
int movex[5]= {1,0,-1,0};
int movey[5]= {0,1,0,-1};
queue<pair<int,int>>q;

void BFS()
{
    while(q.size())
    {
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=curx+movex[i];
            int ny=cury+movey[i];
            if(nx>=1&&nx<=maxRow&&ny>=1&&ny<=maxCol&&vis[nx][ny]==-1)
            {
                vis[nx][ny]=vis[curx][cury]+1;
                q.push({nx,ny});
            }
        }
    }
}


int main()
{

freopen("input.txt", "r",stdin);
freopen("output.txt", "w",stdout);


    memset(vis,-1,sizeof(vis));
    cin>>maxRow>>maxCol;
    int k;
    cin>>k;
    for(int i=0; i<k; i++)
    {
        cin>>x>>y;
        vis[x][y]=0;
        q.push({x,y});
    }

    BFS();
    int ans=-1,posx,posy;
    for(int i=1; i<=maxRow; i++)
    {
        for(int j=1; j<=maxCol; j++)
        {
            if(ans<vis[i][j])
            {
                ans=vis[i][j];
                posx=i;
                posy=j;
            }
        }

    }

    cout<<posx<<" "<<posy<<endl;

    return 0;
}
