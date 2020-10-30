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
int n = 50;
int t = 1000;
int main()
{
    vector<string> g(n);
    rep(i, n)
    {
        cin >> g[i];
    }
    int sy, sx;
    int py, px;
    rep(i, n)
    {
        rep(j, n)
        {
            if (g[i][j] == 'W') {
                py = i;
                px = j;
                i = n;
                break;
            }
        }
    }
    int lowestCost = IINF;
    rep(i, n)
    {
        rep(j, n)
        {
            if (g[i][j] == '.') {
                int currentCost = abs(i - py) + abs(j - px);
                if (currentCost < lowestCost) {
                    sy = i;
                    sx = j;
                    lowestCost = currentCost;
                }
            }
        }
    }
    rep(i, t)
    {
        if (i % 2 == 0)
            cout << "plant " << sx + 1 << " " << sy + 1 << endl;
        else
            cout << "harvest " << sx + 1 << " " << sy + 1 << " " << sx + 1 << " " << sy + 1 << endl;
    }
    return 0;
}