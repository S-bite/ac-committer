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
int n, m;
int dist(int x, int y)
{
    return min(abs(x - y), n - abs(x - y));
}
int main()
{
    cin >> n >> m;
    int a = 0;
    int b = n - 1;

    rep(i, m)
    {
        cout << a + 1 << " " << b + 1 << endl;
        a = (a - 1 + n) % n;
        b = (b + 1) % n;
        if (i + 1 == n / 2)
        {
            b = (b + 1) % n;
        }
    }
    return 0;
}
