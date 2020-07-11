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

VL pp(2 * 101010, 0);
VL pm(2 * 101010, 0);

int calc(string &s, int c, int x, int ind)
{
    // cerr << "*" << s << " " << ind << " " << c << endl;
    if (c == 0)
        return 0;

    int cur = 1;
    if (s[ind] == '1')
    {
        x += pp[s.size() - 1 - ind];
        x %= c;
    }
    else
    {
        x += c - pm[s.size() - 1 - ind];
        x %= c;
    }

    int ret = 0; //cerr << x << endl;
    ret++;
    while (x != 0)
    {
        //   cerr << "*" << x << endl;
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
    pm[0] = 1;
    if (c > 1)
        rep(i, n)
        {
            pm[i + 1] = pm[i] * 2;
            pm[i + 1] %= c - 1;
        }
    pp[0] = 1;
    rep(i, n)
    {
        pp[i + 1] = pp[i] * 2;
        pp[i + 1] %= c + 1;
    }

    int xp = 0;
    int xm = 0;
    int curp = 1;
    int curm = 1;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            xp += curp;
            xp %= (c + 1);
            if (c > 1)
            {
                xm += curm;
                xm %= (c - 1);
            }
        }
        curp *= 2;
        curp %= (c + 1);
        if (c > 1)
        {
            curm *= 2;
            curm %= (c - 1);
        }
    }
    cerr << xp << " " << xm << endl;
    rep(i, n)
    {
        // cerr << i << endl;
        if (s[i] == '0')
        {
            s[i] = '1';
            cout << calc(s, c + 1, xp, i) << "\n";
            s[i] = '0';
        }
        else
        {
            assert(xm != -1);
            s[i] = '0';
            cout << calc(s, c - 1, xm, i) << "\n";
            s[i] = '1';
        }
    }

    return 0;
}
