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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 1;
    rep(i, n)
    {
        int aprev, bprev;
        if (i == 0)
        {
            aprev = 0;
        }
        else
        {
            aprev = a[i - 1];
        }
        if (i == n - 1)
        {
            bprev = 0;
        }
        else
        {
            bprev = b[i + 1];
        }
        //cerr << aprev << " " << bprev << endl;
        if (aprev == a[i] && bprev == b[i])
        {
            ans *= min({a[i], b[i]});
        }
        else if (aprev == a[i] && bprev != b[i])
        {
            ans *= (bprev <= a[i] ? 1 : 0);
        }
        else if (aprev != a[i] && bprev == b[i])
        {
            ans *= (aprev <= b[i] ? 1 : 0);
        }
        else if (aprev != a[i] && bprev != b[i])
        {
            ans *= (a[i] == b[i] ? 1 : 0);
        }
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
