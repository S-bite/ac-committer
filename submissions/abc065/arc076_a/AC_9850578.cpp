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

const ll MOD = 1e9 + 7;

ll frac(ll n)
{
    if (n == 0)
    {
        return 1;
    }
    return (n * frac(n - 1)) % MOD;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    if (abs(n - m) >= 2)
    {
        cout << 0 << endl;
    }
    else if (abs(n - m) == 1)
    {
        cout << (frac(n) * frac(m)) % MOD << endl;
    }
    else
    {
        cout << (2 * frac(n) * frac(m)) % MOD << endl;
    }

    return 0;
}
