#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
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

string bs(ll a)
{
    string ret = "";
    while (a > 0)
    {
        if ((a & 1) == 1)
        {
            ret += "1";
        }
        else
        {
            ret += "0";
        }
        a >>= 1;
    }
    reverse(ALL(ret));
    return ret;
}

ll calc(ll rem, ll bits)
{
    cerr << "rem " << rem << " bits" << bits << endl;
    ll ret = 0;
    ret += rem / (1ll << bits);
    rem %= (1ll << bits);
    cerr << rem << endl;
    if (rem == 0)
    {
        return ret;
    }
    string s = bs(rem);
    int n = s.size();
    assert(s.size() <= bits);
    rep(i, 1, (int)s.size() - 1)
    {
        if (s[i - 1] == '0' && s[i] == '1' && s[i + 1] == '0')
        {
            s[i] = '!';
        }
    }

    if (n >= 2 && s[n - 1] == '1' && s[n - 2] == '0')
    {
        s[n - 1] = '!';
    }
    if (n >= 2 && s[0] == '1' && s[1] == '0')
    {
        s[0] = '!';
    }

    rep(i, 1, (int)s.size() - 1)
    {
        if (s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1')
        {
            s[i] = '1';
            ret++;
        }
    }
    rep(i, n)
    {
        if (s[i] == '!')
            s[i] = '1';
    }

    cerr << s << endl;
    ll cur = 0;
    rep(i, s.size())
    {
        if (s[i] == '0')
        {
            ret += min(cur, 2ll);
            cur = 0;
        }
        else
        {
            cur++;
        }
    }
    ret += min(cur, 2ll);
    cerr << "ret " << ret << endl;
    return ret;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    if (a >= b)
    {
        cout << a - b << endl;
        return 0;
    }
    ll ans = INF;
    rep(i, 64)
    {
        if (a >= b)
        {
            chmin(ans, (ll)i + llabs(a - b));
            chmin(ans, (ll)i + calc(a - b, (ll)i));
            break;
        }
        ll tmp = calc(b - a, (ll)i);
        cerr << "tmp " << tmp << endl;
        chmin(ans, (ll)i + tmp);
        cerr << ans << endl;
        a *= 2;
    }
    assert(ans >= 0);
    cout << ans << endl;
    return 0;
}