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

ll pow(ll base, ll num, ll mod)
{
    if (num == 0)
        return 1;
    ll prev = pow(base, num / 2, mod);
    if (num % 2 == 0)
    {
        return (prev * prev) % mod;
    }
    else
    {
        return (((prev * prev) % mod) * base) % mod;
    }
}

int main()
{

    int n;
    cin >> n;

    VL v(n);
    ll sgcd = v[0];
    bool f1 = true;
    ll curmul = 1;
    VL fact(1000000 + 5, 0);
    rep(i, n)
    {
        cin >> v[i];
        sgcd = gcd(sgcd, v[i]);
        int x = v[i];
        int cur = 2;
        while (cur * cur <= x)
        {
            if (x % cur == 0)
            {
                while (x % cur == 0)
                {
                    x /= cur;
                }
                fact[cur]++;
            }
            cur++;
        }
        if (x != 1)
            fact[cur]++;
    }
    rep(i, 1000000 + 5)
    {
        f1 &= (fact[i] <= 1);
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
