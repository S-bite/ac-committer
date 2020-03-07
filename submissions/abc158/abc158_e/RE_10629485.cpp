#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if (p != 2)
    {
        map<int, ll> mp;
        ll cur = 0;
        ll tmp = 1;
        mp[cur]++;
        for (int i = n - 1; i >= 0; i--)
        {
            cur += (tmp * (ll)(s[i] - '0'));
            cur %= p;
            mp[cur]++;
            tmp *= 10;
            tmp %= p;
            assert(tmp != 0);
        }
        ll ans = 0;
        rep(i, p)
        {
            if (mp[i] == 0)
                continue;
            ans += (ll)mp[i] * (mp[i] - 1) / 2;
        }
        cout << ans << endl;
    }
    else
    {
        ll ans = 0;
        rep(i, n)
        {
            if ((s[i] - '0') % 2 == 0)
            {
                ans += i + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
