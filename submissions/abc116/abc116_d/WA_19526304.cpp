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
    int n, k;
    cin >> n >> k;
    vector<pair<ll, int>> v(n);
    rep(i, n)
    {
        cin >> v[i].second >> v[i].first;
    }
    sort(ALL(v), greater<pair<ll, int>>());
    set<int> types;
    ll ans = 0;
    ll base = 0;
    multiset<pair<ll, int>> ms;
    rep(i, k)
    {
        base += v[i].first;
        types.insert(v[i].second);
    }

    ans = base + (ll)types.size() * (ll)types.size();
    rep(i, k, n)
    {
        if (ms.empty())
            break;
        if (types.find(v[i].first) != types.end())
        {
            continue;
        }
        base += v[i].first;
        base -= (*ms.begin()).first;
        types.insert(v[i].first);
        ms.erase(ms.begin());
        chmax(ans, base + (ll)types.size() * (ll)types.size());
    }
    cout << ans << endl;
    return 0;
}
