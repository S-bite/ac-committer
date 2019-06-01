#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
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
const ll MOD = ((ll)1e9 + 7);
ll pow(ll x, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    ll p = pow(x, n / 2) % MOD;
    return (((p * p) % MOD) * (n % 2 == 1 ? x : 1)) % MOD;
}

ll inv(ll n)
{
    return pow(n, MOD - 2) % MOD;
}

ll gcm(ll a, ll b)
{
    if (b > a)
    {
        int t = b;
        b = t;
        a = t;
    }
    if (b == 0)
    {
        return a;
    }
    return gcm(b, a % b);
}

void ans(ll p, ll q)
{

    cerr << p << "/" << q << endl;
    ll g = gcm(p, q);
    p /= g;
    q /= g;
    cerr << q << "," << inv(q) << endl;
    cout << (p * inv(q)) << endl;
}

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    int c[n];
    map<int, vector<int>> g;
    pair<int, int> p[n];
    rep(i, n)
        p[i] = {0, i};
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        p[a].first++;
        p[b].first++;
        g[b].push_back(a);
        g[a].push_back(b);
    }
    rep(i, n)
    {
        cin >> c[i];
    }

    sort(p, p + n);
    sort(c, c + n);
    ll ans = 0;
    map<int, int> mp;
    rep(i, n)
    {
        mp[p[i].second] = c[i];
    }
    rep(i, n)
    {
        int tmp = 1010101;
        rep(j, g[i].size())
        {
            ans += min(mp[i], mp[g[i][j]]);
        }
    }
    cout << ans / 2 << endl;
    rep(i, n)
    {
        cout << mp[i] << " ";
    }
    cout << endl;
    return 0;
}