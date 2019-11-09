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
#define MOD 998244353ll
using namespace std;

ll mpow(int x, int n)
{
    if (n == 0)
    {
        return 1ll;
    }
    ll prev = mpow(x, n / 2);
    if (n % 2 == 1)
    {
        return (((prev * prev) % MOD) * x) % MOD;
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
    int d[n];
    rep(i, n) cin >> d[i];
    if (d[0] != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(d, d + n);
    if (d[1] != 1)
    {
        cout << 0 << endl;
        return 0;
    }
    rep(i, 1, n - 1)
    {
        if (d[i] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        if (d[i] == d[i + 1] || d[i] + 1 == d[i + 1])
        {
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    ll cur = d[1];
    ll prev = 1;
    ll tmp = 0;

    rep(i, 1, n)
    {
        if (d[i] == cur)
        {
            tmp++;
        }
        else
        {
            cerr << prev << " " << tmp << endl;
            ans *= mpow(prev, tmp);
            ans %= MOD;
            cur = d[i];
            prev = tmp;
            tmp = 1;
        }
    }
    if (tmp != 0)
    {
        ans *= mpow(prev, tmp);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
