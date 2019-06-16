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

int main()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    ll sum[n + 1];
    sum[0] = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum[i + 1] = a[i] + sum[i];
    }
    ll ans = 0;
    rep(i, n)
    {
        ll m = sum[i];
        ll l = i, r = n;
        while (l + 1 != r)
        {
            ll med = (l + r) / 2;
            if (sum[med] - m >= k)
            {
                r = med;
            }
            else
            {
                l = med;
            }
        }
        if (sum[r] - m >= k)
        {
            //cerr << i << "," << r << "," << m << "," << sum[r] << endl;

            ans += n - r + 1;
        }
    }
    cout << ans << endl;
    return 0;
}