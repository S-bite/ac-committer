#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    ll n, y;
    cin >> n >> y;
    rep(i, n + 1) rep(j, n + 1 - i)
    {
        ll rem = y - 10000 * i - 5000 * j;
        rem /= 1000;
        if (rem < 0)
            continue;
        if (i + j + rem == n)
        {
            cout << i << " " << j << " " << rem << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}
