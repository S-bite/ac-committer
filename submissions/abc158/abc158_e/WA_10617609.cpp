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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    map<int, int> mp;
    int cur = 0;
    int tmp = 1;
    mp[cur]++;
    for (int i = n - 1; i >= 0; i--)
    {
        cur += ((s[i] - '0') * tmp) % p;
        cur %= p;
        mp[cur]++;
        tmp *= 10;
        tmp %= p;
    }
    ll ans = 0;
    rep(i, p)
    {
        ans += (ll)mp[i] * (mp[i] - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}
