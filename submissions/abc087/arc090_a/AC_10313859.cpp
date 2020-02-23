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
    int n;
    cin >> n;
    int c[2][100];
    rep(i, n) cin >> c[0][i];
    rep(i, n) cin >> c[1][i];
    int sum[n + 1];
    sum[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum[i] = sum[i + 1] + c[1][i];
    }
    int cur = 0;
    int ans = -1;
    rep(i, n)
    {
        cur += c[0][i];
        ans = max(ans, cur + sum[i]);
    }
    cout << ans << endl;

    return 0;
}
