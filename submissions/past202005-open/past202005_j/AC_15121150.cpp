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
    int n, m;
    cin >> n >> m;
    VI a(m);
    VI cur(n, -1);
    rep(i, m) cin >> a[i];

    rep(i, m)
    {
        if (a[i] > cur[0])
        {
            cout << 1 << endl;
            cur[0] = a[i];
            continue;
        }
        int ng = 0;
        int ok = n;
        while (ng + 1 != ok)
        {
            int mid = (ok + ng) / 2;
            if (cur[mid] >= a[i])
            {
                ng = mid;
            }
            else
            {
                ok = mid;
            }
        }
        if (ok == n)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ok + 1 << endl;
            cur[ok] = a[i];
        }
    }

    return 0;
}
