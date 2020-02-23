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
    n += 2;
    vector<ll> v(n, 0), sum(n + 1, 0);
    rep(i, n) cin >> v[i + 1];
    rep(i, n - 1) sum[i + 1] = sum[i] + labs(v[i + 1] - v[i]);
    //rep(i, n) cerr << sum[i] << endl;
    rep(i, 1, n - 1)
    {
        cout << sum[i - 1] + (sum[n - 1] - sum[i + 1]) + labs(v[i - 1] - v[i + 1]) << endl;
        ;
    }
    return 0;
}
