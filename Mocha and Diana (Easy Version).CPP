#include <bits/stdc++.h>
#define s second
#define f first
#define ll long long

using namespace std;

const int N = 1e3 + 5, M = 2 * N;
int n, par1[N], par2[N], x[N], y[N];
void init(int n)
{
    iota(par1, par1 + n, 0);
    iota(par2, par2 + n, 0);

}

int getParent(int u,int *par)
{
    if(par[u] == u) return u;
    return par[u] = getParent(par[u],par);
}
bool check(int u, int v,int *par)
{
    u = getParent(u,par);
    v = getParent(v,par);
    if(u == v)
        return false;

    return true;
}
void connect( int u, int v,int *par)
{
    u = getParent(u,par);
    v = getParent(v,par);
    par[v] = u;
}


int t=0;


int main()
{
    int n,m1,m2,ans=0;
    cin>>n>>m1>>m2;
        init(n);

    for(int i=0; i<m1; i++)
    {
        int f,t;
        cin>>f>>t;
        connect(--f,--t,par1);
    }
    for(int i=0; i<m2; i++)
    {
        int f,t;
        cin>>f>>t;
        connect(--f,--t,par2);
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        {
            //cout<<i+1<<" "<<j+1<<endl;
            //cout<<getParent(i,par1)<<" "<<getParent(j,par1)<<" "<<getParent(i,par2)<<" "<<getParent(j,par2)<<endl;
            if(getParent(i,par1)!=getParent(j,par1)&&getParent(i,par2)!=getParent(j,par2))
            {
                connect(i,j,par1);
                connect(i,j,par2);
                ans++;
                x[t]=i;
                y[t]=j;
                t++;

            }
        }
    cout<<ans<<endl;

for(int i=0;i<t;i++)
    cout<<x[i]+1<<" "<<y[i]+1<<endl;


    return 0;
}
