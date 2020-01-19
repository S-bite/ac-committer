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

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        ll t = a;
        a = b;
        b = t;
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll mpow(ll base, ll n)
{
    if (n == 0)
    {
        return 1ll;
    }
    ll prev = mpow(base, n / 2);
    if (n % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        return (((prev * prev) % MOD) * base) % MOD;
    }
}

ll lcm(ll a, ll b)
{
    return ((a * b) / gcd(a, b)); //::% MOD;
    //% MOD; // % MOD;
}

map<ll, int> fact(ll n, vector<ll> &p)
{
    int i = 0;
    map<ll, int> ret;
    while (n != 1)
    {
        if (n % p[i] == 0)
        {
            while (n % p[i] == 0)
            {
                ret[p[i]]++;
                n /= p[i];
            }
        }
        i++;
    }
    return ret;
}

bool isprime(ll n)
{
    ll c = 2;
    while (c * c < n)
    {
        if (n % c == 0)
            return false;
        c++;
    }
    return true;
}
int main(int argc, char const *argv[])
{

    vector<ll> prime;
    rep(i, 2, 1e6)
    {
        if (isprime(i))
        {
            prime.push_back(i);
        }
    }
    cerr << 1 << endl;
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    map<int, int> l;

    rep(i, n)
    {
        auto ret = fact(a[i], prime);
        for (auto x : ret)
        {
            l[x.first] = max(l[x.first], x.second);
        }
    }
    ll l2 = 1;
    for (auto x : l)
    {
        l2 *= mpow(x.first, x.second);
        l2 %= MOD;
    }
    ll ans = 0;
    rep(i, n)
    {
        ans += l2 * mpow(a[i], MOD - 2);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
