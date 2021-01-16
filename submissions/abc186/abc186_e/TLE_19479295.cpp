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
const ll MOD = 998244353;
// from : https://qiita.com/drken/items/b97ff231e43bce50199a
long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve()
{
    ll n, s, k;
    cin >> n >> s >> k;
    s = n - s;
    // cerr << k << " " << n << " " << s << endl;
    if (s % gcd(k, n) != 0)
    {
        cout << -1 << endl;
        return;
    }
    ll x, y;
    extGCD(k, n, x, y);
    x *= s / gcd(k, n);
    y *= s / gcd(k, n);
    while (x < 0)
    {
        x += n / gcd(k, n);
    }
    x %= n / gcd(k, n);
    cout << x << endl;
}
int main()
{
    int t;
    cin >> t;
    rep(i, t) { solve(); }
}