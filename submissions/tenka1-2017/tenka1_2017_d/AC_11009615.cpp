#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int main()
{
    int n, k;
    cin >> n >> k;
    map<int, bool> mp;
    map<int, ll> dp;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> v;
    rep(i, n) cin >> a[i] >> b[i];
    mp[k] = true;
    mp[0] = true;
    v.push_back(0);
    v.push_back(k);

    rep(i, 30 + 1)
    {
        if (((k >> (30 - i)) & 1) == 1)
        {
            //cerr << i << endl;
            int tmp = ((k >> (31 - i)) << (31 - i));
            tmp |= ((1 << (30 - i)) - 1);
            // cerr << bitset<30>(tmp) << endl;
            mp[tmp] = true;
            v.push_back(tmp);
        }
    }
    map<int, int> used;

    rep(i, n)
    {
        used.clear();
        for (auto x : v)
        {
            if (mp[(x | a[i])] == false || used[(x | a[i])] == true)
            {
                continue;
            }
            used[(x | a[i])] = true;
            dp[(x | a[i])] += b[i];
        }
    }
    ll ans = 0;
    for (auto x : v)
    {
        chmax(ans, dp[x]);
    }
    cout << ans << endl;
    return 0;
}