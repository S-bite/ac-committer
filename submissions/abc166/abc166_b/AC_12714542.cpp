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
    rep(i, k)
    {
        int d;
        cin >> d;
        rep(j, d)
        {
            int t;
            cin >> t;
            mp[t] = true;
        }
    }
    int ans = n;
    rep(i, 1, n + 1)
    {
        if (mp[i])
            ans--;
    }
    cout << ans << endl;
    return 0;
}