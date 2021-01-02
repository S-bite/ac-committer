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
using Edge = PII;
map<Edge, int> dir;
map<Edge, bool> down;

map<Edge, int> cost;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

void calcdir(VVI &g, int cur, int prev)
{

    for (auto next : g[cur])
    {
        if (next == prev)
        {
            continue;
        }
        down[{cur, next}] = true;
        calcdir(g, next, cur);
    }
}

void recans(VVI &g, VL &ans, vector<ll> &gain, int cur, int prev, ll score)
{
    score += gain[cur];
    ans[cur] = score;
    for (auto next : g[cur])
    {
        if (next == prev)
        {
            continue;
        }
        recans(g, ans, gain, next, cur, score);
    }
}

int main()
{
    int n;
    cin >> n;
    VVI g(n);
    vector<Edge> edge;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edge.push_back({a, b});
    }
    calcdir(g, 0, -1);
    vector<ll> gain(n, 0);
    ll cur = 0;
    int q;
    cin >> q;
    rep(i, q)
    {
        int t, e;
        ll x;
        cin >> t >> e >> x;
        e--;
        int a = edge[e].first;
        int b = edge[e].second;
        if (t == 2)
        {
            swap(a, b);
        }
        if (down[{a, b}])
        {
            cur += x;
            gain[b] -= x;
        }
        else
        {
            gain[a] += x;
        }
    }
    VL ans(n, 0);
    recans(g, ans, gain, 0, -1, cur);
    rep(i, n)
    {
        cout << ans[i] << endl;
    }
    return 0;
}