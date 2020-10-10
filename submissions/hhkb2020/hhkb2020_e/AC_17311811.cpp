
#include <atcoder/modint>
#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using namespace atcoder;

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
using mint = modint1000000007;

ll mpow(ll base, ll num)
{
    if (num == 0)
    {
        return 1ll;
    }
    ll prev = mpow(base, num / 2);
    if (num % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        return (((prev * prev) % MOD) * base) % MOD;
    }
}
int h, w;
int k;

int main()
{
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    vector<vector<int>> row(h);
    rep(i, h)
    {
        row[i].push_back(-1);
        rep(j, w)
        {

            if (g[i][j] == '#')
            {
                row[i].push_back(j);
            }
            else
            {
                k++;
            }
        }
        row[i].push_back(w);
    }
    vector<vector<int>> col(w);
    rep(i, w)
    {
        col[i].push_back(-1);
        rep(j, h)
        {

            if (g[j][i] == '#')
            {
                col[i].push_back(j);
            }
        }
        col[i].push_back(h);
    }
    //  cerr << k << " " << mpow(mint(2), mint(k)).val() << endl;
    ll ans = (mpow(2, k) * k) % MOD;
    //cerr << ans << endl;
    rep(i, h) rep(j, w)
    {
        if (g[i][j] == '#')
            continue;
        int rowl = *(lower_bound(ALL(row[i]), j) - 1);
        int rowr = *(lower_bound(ALL(row[i]), j));
        int coll = *(lower_bound(ALL(col[j]), i) - 1);
        int colr = *(lower_bound(ALL(col[j]), i));
        int affect = (rowr - rowl - 1) + (colr - coll - 1) - 1;

        // cerr << i << " " << j << " " << affect << endl;
        //cerr << "@ " << rowr << " " << rowl << " " << colr << " " << coll << endl;
        ans -= mpow(2, k - affect);
        if (ans < 0)
            ans += MOD;
    }
    cout << ans << endl;

    return 0;
}