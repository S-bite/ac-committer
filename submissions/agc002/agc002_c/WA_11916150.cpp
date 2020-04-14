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
    int n;
    ll l;
    cin >> n >> l;
    VL v(n);
    rep(i, n) cin >> v[i];
    rep(i, n - 1)
    {
        if (v[i] + v[i + 1] >= l)
        {
            VI ans;
            ans.push_back(i);
            rep(j, i) ans.push_back(j);
            rep(j, i + 1, n - 1) ans.push_back(j);
            reverse(ALL(ans));
            cout << "Possible" << endl;
            for (const auto &x : ans)
                cout << x + 1 << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}