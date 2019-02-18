#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main()
{
    map<char, ll> mp;
    string s;
    cin >> s;
    rep(i, s.size())
    {
        mp[s[i]]++;
    }
    ll mx = 0, ans = 0;
    for (auto item : mp)
    {
        mx += item.second - (item.second % 2);
        ans += item.second % 2;
    }
  //  cout << mx << "," << ans << endl;
    mx += min(ans, 1ll);
    ans = max(0ll, ans - 1);
    cout << ans + mx * mx << endl;
    return 0;
}
