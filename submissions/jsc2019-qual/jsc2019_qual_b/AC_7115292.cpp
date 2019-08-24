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
ll MOD = 1000000007ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    rep(i, n) cin >> a[i];
    map<int, ll> mp, mp2;
    rep(i, n) rep(j, i + 1, n)
    {
        if (a[i] > a[j])
            mp[i]++;

        if (a[j] > a[i])
            mp2[j]++;
    }
    ll ans = 0;
    ll kk = k * (k + 1) / 2;
    ll kk2 = k * (k - 1) / 2;
    kk2 %= MOD;

    kk %= MOD;
    rep(i, n)
    {
        ans += mp[i] * kk;
        ans %= MOD;
        ans += mp2[i] * kk2;
        ans %= MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}
