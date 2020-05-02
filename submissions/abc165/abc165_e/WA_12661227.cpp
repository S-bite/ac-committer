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
    int half;
    if (m % 2 == 1)
    {
        half = n / 2 - 1;
    }
    else
    {
        half = n / 2;
    }
    int a = 0, b = half, c = half + 1, d = n - 1;

    rep(i, m)
    {
        if (a + 1 < b)
        {
            cout << a + 1 << " " << b + 1 << endl;
            cerr << dist(a + 1, b + 1) << endl;

            a++;
            b--;
        }
        else
        {
            cout << c + 1 << " " << d + 1 << endl;
            cerr << dist(c + 1, d + 1) << endl;

            c++;
            d--;
        }
    }
    return 0;
}
