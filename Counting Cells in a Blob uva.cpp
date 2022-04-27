#include <bits/stdc++.h>

using namespace std;
int const N=30;

bool vis[N][N];
string arr[30];


int n,m,cnt=1,ans=0;
int movex[] = { 1,-1,-1, 1, 1,-1, 0 ,0};
int movey[] = { 1, 1,-1,-1, 0, 0, -1,1 };
void init()
{


    memset(vis,0,sizeof(vis));

    cnt=1;
    ans=0;

}
void BFS(int x,int y)
{
    queue<pair<int,int>>q;
    vis[x][y]=1;
    q.push({x,y});
    //cout<<x<<" "<<y<<endl;
    while(q.size())
    {
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
           int nx=curx+movex[i];
           int ny=cury+movey[i];

           //cout<<" old "<<nx<<" "<<ny<<endl;
            if(nx>=0&&nx<=m-1&&ny>=0&&n>=ny&&arr[nx][ny]=='1'&&vis[nx][ny]==0)
            {
                //cout<<" new "<<nx<<" "<<ny<<endl;
                cnt++;
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }

    }
}


int main()
{

    int t;
    cin>>t;
string p;
 cin.ignore(100, '\n');
  cin.ignore(100, '\n');
    while(t--)
    {
       init();

       int k=0;
       m=0;
       n=0;
       string s;

   while(getline(cin,s))
   {
       int x=s.size();
         n=max(x,n);

        if(s.size()==0)
            break;

            arr[k]=s;
            k++;
            m++;
   }

   for(int i=0;i<m;i++)
   {
    for(int j=0;j<n;j++)
        {
            if(vis[i][j]==0&&arr[i][j]=='1')
            {
                BFS(i,j);
                ans=max(ans,cnt);
                cnt=1;
            }
        }
   }
cout<<ans<<endl;
if(t)
cout<<endl;

    }


}
