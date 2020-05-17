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

lld dist(lld ax, lld ay, lld bx, lld by)
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

int main()
{
    lld a, b, h, m;
    cin >> a >> b >> h >> m;
    lld arad = (M_PI / 2 - h / 12.0 * 2 * M_PI) - 2 * M_PI / 12 * (m / 60);
    lld brad = (M_PI / 2 - m / 60.0 * 2 * M_PI);
    lld ax = a * cos(arad);
    lld ay = a * sin(arad);
    lld bx = b * cos(brad);
    lld by = b * sin(brad);
    cout << fixed << setprecision(18) << dist(ax, ay, bx, by) << endl;
    return 0;
}