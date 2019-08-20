#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<ll> l, r;
    ll lsum = 0, rsum = 0;
    vector<ll> a(3 * n, 0);
    vector<ll> maxl(3 * n, -1);
    vector<ll> minr(3 * n, -1);

    rep(i, 3 * n) cin >> a[i];
    rep(i, n)
    {
        l.push(-a[i]);

        lsum += a[i];
    }
    maxl[n - 1] = lsum;

    rep(i, n, 2 * n)
    {
        //cerr << lsum << "," << rsum << "," << a[i] << endl;
        if (a[i] > -l.top())
        {
            lsum -= -l.top();
            lsum += a[i];

            l.pop();
            l.push(-a[i]);
        }
        maxl[i] = lsum;
    }

    for (int i = 3 * n - 1; i >= 2 * n; i--)
    {
        r.push(a[i]);
        rsum += a[i];
    }
    minr[2 * n] = rsum;
    for (int i = 2 * n - 1; i >= n; i--)
    {
        if (a[i] < r.top())
        {
            rsum -= r.top();
            rsum += a[i];
            r.pop();
            r.push(a[i]);
        }
        minr[i] = rsum;
        //  cerr << "min " << i << " : " << minr[i] << endl;
    }
    ll ans = -1;
    rep(i, n, 2 * n - 1)
    {
        ans = max(ans, maxl[i] - minr[i + 1]);
    }
    cout << ans << endl;
    return 0;
}