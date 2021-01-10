#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int main()
{
    int n;
    ll C;
    cin >> n >> C;
    vector<pair<ll, ll>> v;
    rep(i, n)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, c});
        v.push_back({b + 1, -c});
    }
    sort(ALL(v));
    ll ans = 0;
    ll cur = 0;
    ll prev = -1;
    rep(i, v.size())
    {
        ans += min(cur, C) * (v[i].first - prev);
        prev = v[i].first;
        cur += v[i].second;
    }
    cout << ans << endl;
    return 0;
}