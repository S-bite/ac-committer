#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    ll ans = 1;
    rep(i, n)
    {
        ans *= (i + 1);
        ans %= MOD;
        cerr << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
