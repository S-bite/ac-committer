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

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        swap(a, b);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

int main()
{

    int n;
    cin >> n;
    vector<ll> mods = {
        (ll)1000000000 + 7ll,
        (ll)1000000000 + 9ll,
        (ll)1000000000 + 21ll,
        (ll)1000000000 + 33ll};
    vector<ll> lcms(4, 1);
    vector<ll> muls(4, 1);

    VL v(n);
    ll sgcd = v[0];
    bool f1 = true;
    ll curmul = 1;
    rep(i, n)
    {
        cin >> v[i];
        sgcd = gcd(sgcd, v[i]);
        rep(j, 4)
        {
            lcms[j] = lcm(muls[j], v[i]) % mods[j];
            muls[j] = (muls[j] * v[i]) % mods[j];
        }
        // cerr << lcms[0] << " " << muls[0] << endl;
    }
    rep(i, 4)
    {
        cerr << lcms[i] << " " << muls[i] << endl;
        f1 &= lcms[i] == muls[i];
    }
    bool f2 = sgcd == 1;
    if (f1)
    {
        cout << "pairwise coprime" << endl;
    }
    else if (f2)
    {
        cout << "setwise coprime" << endl;
    }
    else
    {
        cout << "not coprime" << endl;
    }

    return 0;
}