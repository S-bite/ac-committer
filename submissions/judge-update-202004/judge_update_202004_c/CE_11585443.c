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
int a, b, c;
bool check(VI &va, VI &vb, VI &vc)
{
    rep(i, a - 1)
    {
        if (va[i + 1] <= va[i])
            return false;
    }
    rep(i, b - 1)
    {
        if (vb[i + 1] <= vb[i])
            return false;
    }
    rep(i, c - 1)
    {
        if (vc[i + 1] <= vc[i])
            return false;
    }
    rep(i, c)
    {
        if (vc[i] <= vb[i])
            return false;
    }
    rep(i, b)
    {
        if (vb[i] <= va[i])
            return false;
    }
    return true;
}
int main()
{
    cin >> a >> b >> c;
    int sum = a + b + c;
    VI order(sum);
    iota(ALL(order), 1);
    VI va(a);
    VI vb(b);
    VI vc(c);
    int ans = 0;
    do
    {
        rep(i, a)
        {
            va[i] = order[i];
        }
        rep(i, b)
        {
            vb[i] = order[a + i];
        }
        rep(i, c)
        {
            vc[i] = order[a + b + i];
        }
        if (check(va, vb, vc))
            ans++;
    } while (next_permutation(ALL(order)));
    cout << ans << endl;
    return 0;
}