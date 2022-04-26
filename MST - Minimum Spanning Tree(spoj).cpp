#include <bits/stdc++.h>

#define  f first
#define  s second

using namespace std;
const int n=1e4+10,m=1e5+10;
int per[n],cnt[n];
int x,y,c,u,v,num_comp;

void init()
{
    iota(per,per+n,0);
    fill(cnt, cnt + n, 1);
    num_comp=x;
}
int getPerant(int u)
{
    if(u==per[u])
        return u;
    return per[u]=getPerant(per[u]);
}
bool connect(int u, int v)
{
	u = getPerant(u);
	v = getPerant(v);
	if(u == v) return false;
	if(cnt[u] < cnt[v]) swap(u, v);
	per[v] = u;
	cnt[u] += cnt[v];
	return true;
}


priority_queue<pair<int,pair<int,int>>>pq;

long long mst()
{
    long long  ans=0;
    //cout<<pq.size()<<endl;
while(pq.size()&&num_comp>1)
{
    auto e=pq.top();
    int u=e.s.f;
    int v=e.s.s;
    int c=e.f;
    pq.pop();


    if(connect(u,v))
    {
        //cout<<u<<" "<<v<<endl;
        num_comp--;
        ans+=-c;
    }
       // cout<<"no"<<endl;

}

return ans;


}
int main()
{


    cin>>x>>y;
    init();

    for(int i=0;i<y;i++)
    {
        cin>>u>>v>>c;
        pq.push({-c,{u,v}});
    }
    cout<<mst()<<endl;




    return 0;
}
