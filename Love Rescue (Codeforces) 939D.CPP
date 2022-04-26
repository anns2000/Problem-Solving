#include <bits/stdc++.h>
#include <vector>

using namespace std;
int n;
vector<int>par(26);
string a,b;
int FindPar(int u)
{
    if(u==par[u])
        return u;
    return par[u]=FindPar(par[u]);
}
void Join(int a, int b)
{
    a=FindPar(a);
    b=FindPar(b);
    if(a!=b)
    {
        par[b]=a;
    }

}

int main()
{
    iota(par.begin(),par.end(),0);
    vector<pair<char,char>>ans;
cin>>n>>a>>b;
for(int i=0;i<n;i++)
{
        if(FindPar(a[i]-'a')!=FindPar(b[i]-'a'))
    {
        ans.push_back({a[i],b[i]});
        Join(a[i]-'a',b[i]-'a');
    }

}
cout<<ans.size()<<endl;

for(auto p:ans)
{
    cout<<p.first<<" "<<p.second<<endl;
}
    return 0;
}
