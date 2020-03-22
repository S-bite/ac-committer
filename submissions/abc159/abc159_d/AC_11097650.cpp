#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = (1'000'000'000 + 7);

int main()
{
    int n;
    cin >> n;
    VI v(n);
    map<int, ll> mp;
    rep(i, n)
    {
        cin >> v[i];
        v[i]--;
        mp[v[i]]++;
    }
    ll mans = 0;
    rep(i, n)
    {
        mans += mp[i] * (mp[i] - 1) / 2;
    }

    rep(i, n)
    {

        ll ans = mans;
        int val = v[i];
        if (mp[val] >= 2)
            ans = ans - mp[val] * (mp[val] - 1) / 2 + (mp[val] - 1) * (mp[val] - 2) / 2;
        cout << ans << endl;
    }
    return 0;
}