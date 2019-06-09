#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
using namespace std;
#define MOD (ll)(1e9 + 7);

ll modpow(ll a, int n)
{
    if (n == 0)
        return 1;
    ll prev = modpow(a, n / 2);
    if (n % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        return (prev * prev * a) % MOD;
    }
}

ll calc(string &s)
{
    if (s == "0")
    {
        return 1ll;
    }
    if (s == "1")
    {
        return 3ll;
    }
    s.erase(s.begin());
    int n = s.size();
    return (modpow(3, n) + 2 * calc(s)) % MOD;
}

int main()
{
    string s;
    cin >> s;
    cout << calc(s) << endl;
    return 0;
}
