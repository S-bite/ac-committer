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
vector<PII> h;
map<int, int> h2;
map<int, vector<int>> g;
map<int, bool> used;
void update(int cur)
{
    for (auto &&x : g[cur])
    {
        used[x] = true;
    }
}
bool check(int cur)
{
    int curh = h2[cur];
    for (auto &&x : g[cur])
    {
        if (curh <= h2[x])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    h.resize(n);
    rep(i, n)
    {
        cin >> h[i].first;
        h[i].second = i;
        h2[i] = h[i].first;
    }
    sort(ALL(h), greater<PII>());
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    rep(i, n)
    {
        int j = h[i].second;
        if (used[j] == true)
            continue;
        if (check(j))
        {
            ans++;
            update(j);
        }
    }
    cout << ans << endl;
    return 0;
}