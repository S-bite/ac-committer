#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define fir first
#define sec second
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
ll distance(bool clockwise, ll from, ll to, ll l)
{
    if (clockwise)
    {
        if (from < to)
            return to - from;
        else
            return l - (from - to);
    }
    else
    {
        if (from > to)
            return from - to;
        else
            return l - (to - from);
    }
}

int main()
{
    ll l, n;
    cin >> l >> n;
    ll x[n];
    rep(i, n)
    {
        ll t;
        cin >> t;
        x[i] = t;
    }
    sort(x, x + n);
    pair<ll, ll> dp[n + 1][n];
    rep(i, n + 1) rep(j, n)
    {
        dp[i][j].fir = 0;
        dp[i][j].sec = 0;
    }
    for (ll i = 1; i <= n; i++)
    {
        rep(j, i + 1) // clockwise!
        {
            ll bClock = j - 1;
            ll bAntic = n - (i - j);
            ll clockCost, anticCost;
            if (j == 0)
                clockCost = -1;
            else
                clockCost = dp[i - 1][j - 1].fir + distance(true, dp[i - 1][j - 1].sec, x[bClock], l);

            if (bAntic == n)
                anticCost = -1;
            else
                anticCost = dp[i - 1][j].fir + distance(false, dp[i - 1][j].sec, x[bAntic], l);
            if (clockCost > anticCost)
            {
                dp[i][j].fir = clockCost;
                dp[i][j].sec = x[bClock];
            }
            else
            {
                dp[i][j].fir = anticCost;
                dp[i][j].sec = x[bAntic];
            }
        }
    }
    ll ans = -1;
    rep(i, n) ans = max(ans, dp[n][i].fir);
    cout << ans << endl;
    return 0;
}
