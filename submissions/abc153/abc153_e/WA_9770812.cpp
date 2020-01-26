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
const ll INF = (1ll << 60);

map<ll, ll> mp;

bool isok(ll h, ll k, ll n, vector<tuple<double, ll, ll>> &tp)
{
    ll ans = 0;
    rep(i, n)
    {
        auto cura = (get<1>(tp[i]));
        auto curb = (get<2>(tp[i]));
        cerr << (cura) << " " << (k / curb) << endl;
        ans += (cura) * (k / curb);
        k -= curb * (k / curb);
        if (ans >= h)
        {
            break;
        }
    }
    cerr << ans << " " << k << endl;
    return ans >= h;
}

ll f(ll h, vector<ll> &a, vector<ll> &b)
{
    //cerr << h << endl;
    if (h <= 0)
    {
        return 0;
    }

    //cerr << "count " << h << endl;
    if (mp.count(h) == 1)
    {
        return mp[h];
    }
    //cerr << "done " << h << endl;

    ll ans = INF;
    rep(i, a.size())
    {
        rep(j, 1, 1 + (h + a[i] - 1) / a[i])
        {
            ll tmp = f(h - j * a[i], a, b) + j * b[i];
            ans = min(ans, tmp);
        }
    }
    //cerr << ans << endl;
    mp[h] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), b(n);

    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    vector<ll> dp(h + 1, INF);
    dp[0] = 0;
    rep(i, n)
    {
        auto next = dp;
        rep(j, h + 1)
        {
            //  cerr << j << " " << a[i] << endl;

            if (j - a[i] < 0)
            {
                continue;
            }
            if (dp[j] > dp[j - a[i]] + b[i])
            {
                //        cerr << "<" << endl;
            }
            dp[j] = min(dp[j], dp[j - a[i]] + b[i]);
        }
        for (ll j = h - 1; j >= 0; j--)
        {
            if (dp[j] > dp[j + 1])
                dp[j] = dp[j + 1];
        }
        //rep(j, h + 1) cerr << dp[j] << " ";
        //cerr << endl;
        //dp = next;
    }
    cout << dp[h] << endl;
    return 0;
}
