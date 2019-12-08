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

const ll MOD = (1e9 + 7);
ll modpow(ll n)
{
    if (n == 0)
    {
        return 1ll;
    }
    ll prev = modpow(n / 2);
    if (n % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        return (prev * prev * 2) % MOD;
    }
}
int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<ll> one(60, 0);
    vector<ll> zero(60, 0);
    rep(i, n)
    {
        ll a;
        cin >> a;
        rep(j, 60)
        {
            if (((a >> j) & 1) == 1)
            {
                one[j]++;
            }
            else
            {
                zero[j]++;
            }
        }
    }
    ll ans = 0;
    rep(i, 60)
    {
        ans += (one[i] * zero[i] * modpow(i)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
