#include <iostream>
using namespace std;
const int N = 1e6 + 10;
char ans[N], s[N];
int ret = 1e9, n;
void solve(int r, int i){
    int b = r, a = i, c = 0;
    while(a > 0 && b > 0){
        if(b > a) {
            b -= a;
            if(b > i) return;
            s[c++] = 'B';
        }
        else{
            a -= b;
            if(a > i) return;
            s[c++] = 'T';
        }
    }

    if(c != n || min(a, b) != 0 || max(a, b) != 1) return;
    s[c-1] = 'T';
    int dif = 0;
    for(int i = c-1; i > 0; i--)
        dif += s[i] == s[i-1];

    if(dif < ret){
        ret = dif;
        for(int i = 0; i < c; i++)
            ans[c - i - 1] = s[i];
    }
    return;
}

int main()
{
    int r;
cin>>n>>r;
    for(int i = 1; i <= r; i++){
        solve(r, i);
        solve(i, r);
    }
    if(ret == 1e9) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ret<<endl;
    cout<<ans<<endl;
    return 0;
}
