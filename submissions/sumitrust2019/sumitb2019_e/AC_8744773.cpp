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
const ll MOD = 1000000007;
using namespace std;

ll mpow(int base, int n)
{
    if (n == 0)
    {
        return 1ll;
    }
    ll prev = mpow(base, n / 2);
    if (n % 2 == 1)
    {
        return (((prev * prev) % MOD) * base) % MOD;
    }
    else
    {
        return (prev * prev) % MOD;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {

        cin >> a[i];
        a[i]++;
    }
    vector<int> mp(n + 1, 0);
    ll ans = 1;
    rep(i, n)
    {
        if (a[i] == 1)
        {
            ans *= (3 - mp[1]);
            mp[1]++;

            ans %= MOD;
        }
        else
        {
            //  cerr << a[i] << " " << (mp[a[i] - 1] - mp[a[i]]) << endl;
            ans *= (mp[a[i] - 1] - mp[a[i]]);
            ans %= MOD;
            mp[a[i]]++;
        }
    }
    cout << ans << endl;

    return 0;
}
