#pragma GCC optimize("Ofast")
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

const ll INF = 1ll << 60;

int main()
{
    ll n;
    cin >> n;
    ll ans = INF;
    ll cur = 1;

    while (cur * cur <= n)
    {
        if (n % cur == 0)
        {
            chmin(ans, cur - 1 + n / cur - 1);
        }
        cur++;
    }
    cout << ans << endl;
    return 0;
}