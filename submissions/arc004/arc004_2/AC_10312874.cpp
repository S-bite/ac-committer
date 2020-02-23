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
    vector<ll> v(n), sum(n + 1, 0);
    rep(i, n) cin >> v[i];
    sum[0] = 0;
    rep(i, n) sum[i + 1] += sum[i] + v[i];

    cout << sum[n] << " " << max(0ll, (2 * *max_element(ALL(v)) - sum[n])) << endl;
    return 0;
}
