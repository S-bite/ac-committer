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
    while (rem != 0)
    {
        if (rem % 2 == 0)
        {
            rem >>= 1;
            continue;
        }
        ret++;

        if (rem % 4 == 3)
        {
            rem++;
        }
        else
        {
            rem--;
        }
    }
    // string s = bs(rem);
    // cerr << s << endl;
    // int n = s.size();
    // ll cur = 0;
    // rep(i, s.size())
    // {
    //     if (s[i] == '0')
    //     {
    //         cur = 0;
    //     }
    //     else
    //     {
    //         if (cur == 0)
    //         {
    //             ret++;
    //             cur = 1;
    //         }
    //     }
    // }

    // ret += min(cur, 2ll);
    //cerr << "ret " << ret << " flip " << flip << endl;
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