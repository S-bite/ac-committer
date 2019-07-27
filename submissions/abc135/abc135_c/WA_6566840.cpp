#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n + 1];
    int b[n];
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;

    rep(i, n)
    {
        if (a[i] >= b[i])
        {
            ans += b[i];
        }
        else
        {
            ans += a[i];
            b[i] -= a[i];
            if (a[i + 1] >= b[i])
            {
                ans += b[i];
                b[i] = 0;
            }
            else
            {
                ans += a[i + 1];
                b[i] -= a[i + 1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
