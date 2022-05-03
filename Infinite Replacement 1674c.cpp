#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
// problem Link =>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define ll long long
#define pa pair<int,int>
const int INTMAX = 1000000000;
const int N = 200005;
using namespace std;
ll memo[55];
ll factorial(int N)
{
	if (N == 0)
		return 1;
	long long ret = factorial(N / 2);
	ret *= ret;
	if (N & 1)
		ret *= 2;
	return ret;
}
int main()
{
	memset(memo, -1, sizeof memo);
	int t; cin >> t;
	
	for (int k = 1; k <= t; k++)
	{
		// aaaaaa
		string s, b;
		cin >> s >> b;
		int cnt = 0;
		for (int i = 0; i < b.size(); i++)
			if (b[i] == 'a')
				cnt++;
		if (cnt == b.size() && cnt == 1)
			cout << "1\n";
		else 
			if (cnt != 0)cout << "-1\n";
		else {

			cnt = 0;
			for (int i = 0; i < s.size(); i++)
				if (s[i] == 'a')
					cnt++;
			ll x;
			if (cnt == 1) x = 2;
			else
				x = factorial(cnt) ;
			cout << x << '\n';
		}
	}
}
