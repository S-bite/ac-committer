#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const ll MOD = 1000000000 + 7;

ll mpow(ll base, ll n)
{
    if (n == 0)
        return 1;
    ll prev = mpow(base, n / 2);
    if (n % 2 == 1)
    {
        return (prev * prev * base) % MOD;
    }
    else
    {
        return (prev * prev) % MOD;
    }
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    vector<ll> num(n, 0);
    vector<ll> invnum(n, 0);
    vector<ll> smaller(n, 0);
    rep(i, n) rep(j, i + 1, n)
    {
        if (v[i] > v[j])
        {
            num[i]++;
            invnum[j]++;
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            if (v[i] > v[j])
            {
                smaller[i]++;
            }
        }
    }
    ll ans = 0;
    rep(i, n)
    {
        //cerr << i << " " << num[i] << " " << smaller[i] << endl;
        ans += num[i] * k;
        ans %= MOD;
        ll tmp = smaller[i];
        tmp *= ((k - 1) * k / 2) % MOD;
        tmp %= MOD;
        assert(tmp > 0);

        ans += tmp;
        ans %= MOD;
        assert(ans > 0);
    }
    cout << ans << endl;
    return 0;
}