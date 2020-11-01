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

bool check(vector<int>& x, vector<int>& y, int a, int b, int c)
{
    int dx1 = x[a] - x[b];
    int dx2 = x[b] - x[c];

    int dy1 = y[a] - y[b];
    int dy2 = y[b] - y[c];
    return dx2 * dy1 == dx1 * dy2;
}

int main()
{

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    rep(i, n)
    {
        rep(j, i + 1, n)
        {
            rep(k, j + 1, n)
            {
                bool f = false;
                f |= check(x, y, i, j, k);
                f |= check(x, y, j, k, i);
                f |= check(x, y, k, i, j);
                f |= check(x, y, j, i, k);
                f |= check(x, y, k, j, i);
                f |= check(x, y, i, k, j);
                if (f) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}