#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        swap(a, b);
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll mpow(ll base, ll num)
{
    if (num == 0)
        return 1ll;
    ll prev = mpow(base, num / 2);
    if (num % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        return (((prev * base) % MOD) * prev) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    VL a(n), b(n);
    map<PII, ll> mp;

    rep(i, n)
    {
        cin >> a[i] >> b[i];
        ll g = gcd(llabs(a[i]), llabs(b[i]));
        if (g != 0)
        {
            a[i] /= g;
            b[i] /= g;
        }
        mp[{a[i], b[i]}]++;
    }
    map<PII, bool> used;
    ll ans = 1;
    rep(i, n)
    {
        if (a[i] != 0 && b[i] != 0)
        {
            if (used[{a[i], b[i]}])
                continue;
            ll tmp = 1;
            tmp += (mpow(2, mp[{a[i], b[i]}]) * mpow(2, mp[{-a[i], -b[i]}]) - 1) % MOD;
            tmp %= MOD;

            tmp += (mpow(2, mp[{-b[i], a[i]}]) * mpow(2, mp[{b[i], -a[i]}]) - 1) % MOD;
            tmp %= MOD;

            used[{a[i], b[i]}] = true;
            used[{-b[i], a[i]}] = true;
            used[{b[i], -a[i]}] = true;
            used[{-a[i], -b[i]}] = true;

            tmp %= MOD;
            ans *= tmp;
        }
        else if (a[i] != 0 && b[i] == 0)
        {
            if (used[{a[i], b[i]}])
                continue;
            ll tmp = 1;
            tmp += mpow(2, mp[{a[i], b[i]}]) - 1;

            tmp %= MOD;
            tmp += mpow(2, mp[{b[i], a[i]}]) - 1;
            tmp %= MOD;
            tmp += mpow(2, mp[{b[i], -a[i]}]) - 1;
            used[{a[i], b[i]}] = true;
            used[{-b[i], a[i]}] = true;
            used[{b[i], -a[i]}] = true;
            used[{-a[i], -b[i]}] = true;
            tmp %= MOD;
            ans *= tmp;
        }
        else if (a[i] == 0 && b[i] != 0)
        {
            if (used[{a[i], b[i]}])
                continue;
            ll tmp = 1;
            tmp += mpow(2, mp[{a[i], b[i]}]) - 1;
            tmp %= MOD;

            tmp += mpow(2, mp[{b[i], a[i]}]) - 1;
            tmp %= MOD;

            tmp += mpow(2, mp[{-b[i], a[i]}]) - 1;
            used[{a[i], b[i]}] = true;
            used[{-b[i], a[i]}] = true;
            used[{b[i], -a[i]}] = true;
            used[{-a[i], -b[i]}] = true;
            tmp %= MOD;

            ans *= tmp;
        }
        else
        {
            ans += 1;
        }
        ans %= MOD;
    }
    cout << (ans + MOD - 1) % MOD << endl;
    return 0;
}