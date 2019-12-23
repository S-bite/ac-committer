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

ll calc1(vector<ll> &a, vector<int> &one, int n, int limit)
{
    ll ret = 0;
    rep(i, limit)
    {
        int j = max(one[i], n - one[i]);
        ret += (1ll << i) * j;
    }

    return ret;
}

//bit目のみを見たときの最大値
ll calc2(vector<ll> &a, vector<int> &one, int n, int bit)
{
    ll ret = 0;
    int j = max(one[bit], n - one[bit]);
    ret += (1ll << bit) * j;

    return ret;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<int> one(41, 0);
    rep(i, n)
    {
        cin >> a[i];
        rep(j, 41)
        {
            one[j] += ((a[i] >> j) & 1);
        }
    }

    vector<vector<ll>> dp(41, vector<ll>(2, 0)); //dp[i][j]、今jを使ったときの、iビット目までの最大値

    ll ans = -1;
    ll cur = 0;
    if ((k & 1) == 0)
    {
        dp[0][0] = one[0];
    }
    else
    {
        dp[0][0] = n - one[0];
    }
    //dp[0][1] = max((ll)one[0], n - one[0]);

    rep(i, 1, 41)
    {
        int t = (k >> i) & 1;
        //cerr << i << " " << t << endl;
        if (t == 1)
        {
            //cerr << "aaaaa" << endl;
            dp[i][0] = max(calc1(a, one, n, i) + one[i] * (1 << i), (n - one[i]) * (1 << i) + dp[i - 1][0]);
            //dp[i][1] = calc1(a, one, n, i + 1);
        }
        else
        {
            //cerr << one[i];
            dp[i][0] = dp[i - 1][0] + (1ll << i) * one[i];
            //dp[i][1] = calc1(a, one, n, i + 1);
        }
    }
    //cerr << dp[39][1] << endl;
    cout << dp[40][0] << endl;
    return 0;
}