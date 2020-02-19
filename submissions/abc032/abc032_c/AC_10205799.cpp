#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    rep(i, n)
    {
        if (v[i] == 0)
        {
            cout << n << endl;
            return 0;
        }
    }
    if (k == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    ll cur = 1;
    ll ans = 0;
    ll i = 0;
    rep(j, i, n)
    {
        cur *= v[j];
        if (cur > k)
        {
            while (cur > k)
            {
                cur /= v[i];
                i++;
            }
            //j = max(j, i);
        }
        cerr << i << " " << j << " " << cur << endl;
        ans = max(ans, j - i + 1);
    }
    cout << ans << endl;
    return 0;
}
