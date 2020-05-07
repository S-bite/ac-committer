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

bool ok(int i, int j, int n)
{
    return 0 <= i && i < n && 0 < j && j < 2 * n;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    rep(i, n) cin >> v[i];
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j < 2 * n - 2; j++)
        {
            if (v[i][j] == '.')
                continue;
            bool check = false;
            check |= (ok(i + 1, j - 1, n) && v[i + 1][j - 1] == 'X');
            check |= (ok(i + 1, j, n) && v[i + 1][j] == 'X');
            check |= (ok(i + 1, j + 1, n) && v[i + 1][j + 1] == 'X');
            if (check)
                v[i][j] = 'X';
        }
    }
    rep(i, n) cout << v[i] << endl;
    return 0;
}