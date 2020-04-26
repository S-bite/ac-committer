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
int mpow(int base, int n)
{
    if (n == 0)
        return 1;
    int prev = mpow(base, n / 2);
    if (n % 2 == 0)
        return (prev * prev) % 2019;
    else
        return (prev * prev * base) % 2019;
}
int main()
{
    string s;
    cin >> s;
    reverse(ALL(s));
    map<int, int> mp;
    int cur = 0;
    rep(i, s.size())
    {
        cur = mpow(10, i) * (s[i] - '0') + cur;
        cur %= 2019;
        // cerr << cur << endl;
        mp[cur]++;
    }
    mp[0]++;
    ll ans = 0;
    rep(i, 2019)
    {
        if (mp[i] != 0)
        {
            //cerr << i << " " << mp[i] << endl;
        }
        ans += mp[i] * (mp[i] - 1);
    }
    cout << ans / 2 << endl;

    return 0;
}