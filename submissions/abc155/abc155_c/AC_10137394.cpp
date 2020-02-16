#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    vector<pair<int, string>> v;
    for (auto x : mp)
    {
        v.push_back({x.second, x.first});
    }

    sort(ALL(v), greater<pair<int, string>>());
    int mx = v[0].first;
    vector<string> ans;
    rep(i, n)
    {
        if (v[i].first != mx)
            break;
        ans.push_back(v[i].second);
    }
    sort(ALL(ans));
    rep(i, ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}