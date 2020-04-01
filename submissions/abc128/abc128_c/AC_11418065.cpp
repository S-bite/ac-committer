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
int n, m;

bool ok(map<int, VI> &mp, VI &p, VI &k, int order)
{
    vector<int> on(n);
    rep(i, n) on[i] = ((order >> i) & 1);
    bool ret = true;
    rep(i, m)
    {
        int cnt = 0;
        rep(j, k[i])
        {
            cnt += on[mp[i][j]];
        }
        ret &= (cnt % 2 == p[i]);
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    map<int, VI> mp;
    vector<int> k(m);
    rep(i, m)
    {
        cin >> k[i];
        rep(j, k[i])
        {
            int t;
            cin >> t;
            t--;
            mp[i].push_back(t);
        }
    }
    VI p(m);
    rep(i, m) cin >> p[i];
    int ans = 0;
    rep(i, 1 << n)
    {
        if (ok(mp, p, k, i))
            ans++;
    }
    cout << ans << endl;

    return 0;
}
