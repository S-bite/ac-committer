#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n)
    {
        int t;
        cin >> t;
        mp[t]++;
    }
    int ans = 0;
    for (auto x : mp)
    {
        if (x.first > x.second)
            ans += x.second;
        else
            ans += x.second - x.first;
    }
    cout << ans << endl;
    return 0;
}
