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
int main()
{
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    priority_queue<pair<ll, int>> pque;
    rep(i, A)
    {
        ll tmp;
        cin >> tmp;
        pque.push({tmp, 0});
    }
    rep(i, B)
    {
        ll tmp;
        cin >> tmp;
        pque.push({tmp, 1});
    }
    rep(i, C)
    {
        ll tmp;
        cin >> tmp;
        pque.push({tmp, 2});
    }
    ll ans = 0;
    ll rem = X + Y;
    while (X + Y > 0 && rem > 0)
    {
        auto cur = pque.top();
        pque.pop();
        if (cur.second == 0 && X > 0)
        {
            ans += cur.first;
            X--;
            rem--;
        }
        else if (cur.second == 1 && Y > 0)
        {
            ans += cur.first;
            Y--;
            rem--;
        }
        else if (cur.second == 2)
        {
            ans += cur.first;
            rem--;
        }
    }
    cout << ans << endl;
}