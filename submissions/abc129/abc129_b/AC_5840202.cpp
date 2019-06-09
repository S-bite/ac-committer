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
    int n;
    cin >> n;
    vector<int> a(n, 0);
    rep(i, n) cin >> a[i];
    int ans = 10000000;
    rep(t, n)
    {
        int now = 0;
        rep(i, n)
        {
            if (i <= t)
            {
                now += a[i];
            }
            else
            {
                now -= a[i];
            }
        }

        ans = min(ans, abs(now));
    }
    cout << ans << endl;

    return 0;
}