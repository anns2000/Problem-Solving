#include <bits/stdc++.h>

using namespace std;
int x,y,gx,gy;
string n,m;
int const N=1e5+5;
int vis[10][10];
int movex [10]= {1,2, 2,1 ,-1,-2,-2,-1};
int movey [10]= {2,1,-1,-2,-2,-1,1 ,2};

void BFS(int x,int y)
{
    vis[x][y]=0;
    queue<pair<int,int>>que;
    que.push({x,y});
    while(que.size())
    {
        int curx=que.front().first;
        int cury=que.front().second;
        que.pop();
       // cout<<curx<<" "<<cury<<endl;
        if(curx==gx&&cury==gy)
           return ;
        for(int i=0; i<8; i++)
        {
            int nx=curx+movex[i];
            int ny=cury+movey[i];
            //cout<<"try  ="<<" "<<nx<<" "<<ny<<endl;
            if(nx>=1&&nx<=8&&ny<=8&&ny>=1&&vis[nx][ny]==1e9)
            {
                 //cout<<"new  ="<<" "<<nx<<" "<<ny<<endl;
                vis[nx][ny]=vis[curx][cury]+1;
                que.push({nx,ny});
            }
        }
    }
}


int main()
{
    while(cin>>n>>m)
    {
   for(int i=0;i<10;i++)
   {
          for(int j=0;j<10;j++)
          {
              vis[i][j]=1e9;
          }
   }
        x=n[0]-'a'+1;
        y=n[1]-'0';
        gx=m[0]-'a'+1;
        gy=m[1]-'0';
        BFS(x,y);
        cout<<"To get from "<<n<<" to "<<m<<" takes "<<vis[gx][gy]<<" knight moves."<<endl;

    }
    return 0;
}
