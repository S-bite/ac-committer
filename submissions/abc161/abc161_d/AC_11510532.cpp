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
vector<ll> ans;
void dfs(int rem, ll cur)
{
    if (rem == 0)
    {
        ans.push_back(cur);
        return;
    }
    int last = cur % 10;
    rep(i, 10)
    {
        if (abs(last - i) <= 1)
        {
            dfs(rem - 1, cur * 10 + i);
        }
    }
}

int main()
{
    rep(i, 10)
    {
        rep(j, 1, 10)
        {
            dfs(i, j);
        }
    }
    sort(ALL(ans));
    int k;
    cin >> k;
    cout << ans[k - 1] << endl;
    return 0;
}
