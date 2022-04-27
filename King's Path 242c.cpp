#include <bits/stdc++.h>
using namespace std;
int DX[] = { 1,-1,-1, 1, 1,-1, 0 ,0};
int DY[] = { 1, 1,-1,-1, 0, 0, -1,1 };
int BFS(int, int, int, int);
const long long sizee =1000000000;
map<pair<int,int>,int>vis;
bool isvla(int,int);
map<int,vector<pair<int,int>>>mp;
int main()
{

    int n,row,l,r;

     int xr, xc, yr, yc;
     cin>>xr>>xc>>yr>>yc;
 cin>>n;
    while (n--)
    {

        cin>>row>>l>>r;
        mp[row].push_back({l,r});
    }


        int Move =BFS(xr, xc, yr, yc);
        if(Move==-1)
        cout << Move << endl;
        else
            cout<<Move-1<<endl;
    return 0;
}
int BFS(int xr, int xc, int tr, int tc)
{
    vis[{xr,xc}]=1;
    queue<int> Q;

    Q.push(xr);
    Q.push(xc);

    while(!Q.empty())
    {
        int R = Q.front();
        Q.pop();
        int C = Q.front();
        Q.pop();
        if(R==tr&&C==tc) return vis[{R,C}];
        for(int i=0; i<8; ++i)
        {
            int x = C+DX[i];
            int y = R+DY[i];
           // cout<<x<<" x y "<<y<<endl;
            if(isvla(x,y))
            {
                vis[{y,x}]= vis[{R,C}]+1;
                Q.push(y);
                Q.push(x);
            }
        }
    }
    return -1;
}
bool isvla(int x,int y)
{

    if(x<0||y<0||x>sizee||y>sizee||vis[{y,x}]!=0)
        {
        return false;
        }


    bool lol=false;
    for(int i=0;i<mp[y].size();i++)
    {
       // cout<<"anas111"<<endl;
       // cout<<mp[y][i].first<<" xxx "<<mp[y][i].second<<endl;
        if(x>=mp[y][i].first&&x<=mp[y][i].second)
        {
            lol=true;
          //  cout<<"anas1"<<endl;
            break;
        }

    }

    return lol;


}
