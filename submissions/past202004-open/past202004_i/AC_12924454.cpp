#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

map<int, int> ans;

void dfs(vector<PII> &v, int cur)
{
    int n = v.size();
    if (n == 1)
    {

        ans[v[0].first] = cur;
        return;
    }
    vector<PII> next(n / 2);
    for (int i = 0; i < n; i += 2)
    {
        if (v[i].second > v[i + 1].second)
        {
            next[i / 2] = v[i];
            ans[v[i + 1].first] = cur + 1;
        }
        else
        {
            next[i / 2] = v[i + 1];
            ans[v[i].first] = cur + 1;
        }
    }
    dfs(next, cur + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<PII> v(1 << n);
    rep(i, 1 << n)
    {
        v[i].first = i;
        cin >> v[i].second;
    }
    dfs(v, 0);
    rep(i, 1 << n)
    {
        cout << ans[i] << endl;
    }
    return 0;
}