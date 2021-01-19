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
    multiset<pair<ll, int>> removable;
    rep(i, n)
    {
        cin >> v[i].second >> v[i].first;
        v[i].second--;
    }
    sort(ALL(v), greater<pair<ll, int>>());
    vector<int> types(n, 0);
    ll ans = 0;
    ll base = 0;

    ll bonus = 0;
    rep(i, k)
    {

        base += v[i].first;
        if (types[v[i].second] == 0)
            bonus++;
        types[v[i].second]++;
        if (types[v[i].second] >= 2)
        {
            removable.insert(v[i]);
        }
    }
    ans = base + bonus * bonus;
    cerr << ans << endl;
    rep(i, k, n)
    {
        if (removable.empty())
            break;
        if (types[v[i].second] != 0)
        {
            continue;
        }
        base += v[i].first;
        base -= (*removable.begin()).first;
        bonus++;
        types[v[i].second]++;
        removable.erase(removable.begin());
        chmax(ans, base + bonus * bonus);
    }
    cout << ans << endl;
    return 0;
}
