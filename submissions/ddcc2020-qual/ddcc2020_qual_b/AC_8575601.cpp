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
    ll a[n];
    rep(i, n) cin >> a[i];
    ll s[n + 1];
    s[0] = 0;
    rep(i, n)
    {
        s[i + 1] = s[i] + a[i];
    }
    ll ans = (1ll << 60);
    rep(i, 1, n + 1)
    {
        ll llen = s[i];
        ll rlen = s[n] - s[i];
        if (llen == rlen)
        {
            ans = 0;
            break;
        }
        //cerr << i << " " << s[i] << " " << llen << " " << rlen << " " << abs(llen - rlen) << " " << ans << endl;
        ans = min(ans, abs(llen - rlen));
    }
    cout << ans << endl;
    return 0;
}
