#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int popcnt(int x)
{
    int ret = 0;
    while (x != 0)
    {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}

int calc(string &s, int c)
{
    if (c == 0)
        return 0;
    int x = 0;
    int cur = 1;
    int ret = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            x += cur;
            x %= c;
        }
        cur *= 2;
        cur %= c;
    }
    //cerr << x << endl;
    ret++;
    while (x != 0)
    {
        c = popcnt(x);
        x %= c;
        ret++;
    }
    return ret;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int c = 0;
    rep(i, n)
    {
        if (s[i] == '1')
            c++;
    }
    rep(i, n)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            cout << calc(s, c + 1) << endl;
            s[i] = '0';
        }
        else
        {
            s[i] = '0';
            cout << calc(s, c - 1) << endl;
            s[i] = '1';
        }
    }

    return 0;
}
