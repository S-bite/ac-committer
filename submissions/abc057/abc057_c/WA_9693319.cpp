#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int figure_len(ll n)
{
    int ret = 0;
    while (n != 0)
    {
        ret++;
        n /= 10;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    int ans = (1 << 30);
    rep(a, 1, n)
    {
        ll b = n / a;
        if (b < a)
        {
            break;
        }
        if (n % a != 0)
            continue;
        ans = min(ans, max(figure_len(a), figure_len(b)));
    }
    cout << ans << endl;
    return 0;
}
