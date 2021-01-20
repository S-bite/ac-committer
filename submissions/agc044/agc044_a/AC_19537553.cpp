#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define contain(x, y) (x.find(y) != x.end())

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
map<ll, ll> mp;
ll A, B, C, D;
ll solve(ll n)
{
    if (n == 0)
    {
        return 0;
    }
    if (contain(mp, n))
    {
        return mp[n];
    }
    ll tmp = INF;
    if (INF / D > n)
        tmp = D * n;

    assert(tmp > 0);
    chmin(tmp, solve(n / 2) + A + D * (n % 2));
    chmin(tmp, solve(n / 3) + B + D * (n % 3));
    chmin(tmp, solve(n / 5) + C + D * (n % 5));

    ll cost = (2 - (n % 2));
    if (n / 2 + 1 != n)
        chmin(tmp, solve(n / 2 + 1) + A + D * cost);
    cost = (3 - (n % 3));
    if (n / 3 + 1 != n)
        chmin(tmp, solve(n / 3 + 1) + B + D * cost);
    cost = (5 - (n % 5));
    if (n / 5 + 1 != n)
        chmin(tmp, solve(n / 5 + 1) + C + D * cost);
    mp[n] = tmp;
    return mp[n];
}

int main()
{
    int t;
    cin >> t;
    rep(i, t)
    {
        ll N;
        cin >> N >> A >> B >> C >> D;
        mp.clear();
        cout << solve(N) << endl;
    }
}