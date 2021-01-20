#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define contain(x, y) (x.find(y) != x.end())

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
    int n, m;
    cin >> n >> m;
    vector<ll> cake[8];
    rep(i, n)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        cake[0].push_back(x + y + z);
        cake[1].push_back(x + y - z);
        cake[2].push_back(x - y + z);
        cake[3].push_back(x - y - z);
        cake[4].push_back(-x + y + z);
        cake[5].push_back(-x + y - z);
        cake[6].push_back(-x - y + z);
        cake[7].push_back(-x - y - z);
    }
    rep(i, 8)
    {
        sort(ALL(cake[i]), greater<ll>());
    }
    ll ans = -INF;
    rep(i, 8)
    {
        ll cur = 0;
        rep(j, m)
        {
            cur += cake[i][j];
        }
        chmax(ans, cur);
    }
    cout << ans << endl;
}