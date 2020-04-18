#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (a); i < (b); ++i)
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
map<int, vector<int>> g;
vector<vector<PII>> route;
int n;
int m;
ll ans;

vector<PII> findpath(int cur, int par, int dest, vector<PII> path)
{

    //cerr << cur << " " << par << " " << dest << endl;
    if (cur != par)
    {
        path.push_back({min(cur, par), max(cur, par)});
    }
    if (cur == dest)
    {
        return path;
    }
    for (auto &&x : g[cur])
    {
        if (x != par)
        {
            auto ret = findpath(x, cur, dest, path);
            if (ret.size() > 0)
                return ret;
        }
    }
    return {};
}

ll powll(ll base, ll num)
{
    if (num == 0)
    {
        return 1;
    }
    ll prev = powll(base, num / 2);
    if (num % 2 == 0)
    {
        return prev * prev;
    }
    else
    {
        return prev * prev * base;
    }
}

void dfs(int cur, vector<PII> marked, map<PII, bool> skipped)
{
    if (cur == m)
    {
        int num = 0;
        // cerr << "*************" << endl;
        rep(i, n)
        {
            rep(j, i + 1, n)
            {
                if (skipped[{i, j}])
                {
                    num++;
                    //     cerr << i << "," << j << " ";
                }
            }
        }
        //cerr << endl;
        for (auto &&x : marked)
        {
            //     cerr << x.first << "," << x.second << " ";
        }
        // cerr << endl;
        //cerr << n - marked.size() - num << endl;
        assert(n - 1 >= marked.size() + num);
        ans += powll(2, n - 1 - marked.size() - num);
    }
    else
    {
        bool flag = false;
        for (auto &&x : marked)
        {
            if (find(ALL(route[cur]), x) != route[cur].end())
            {
                flag = true;
                dfs(cur + 1, marked, skipped);
                break;
            }
        }
        if (flag == false)
        {
            for (PII x : route[cur])
            {
                if (skipped[x])
                    continue;
                marked.push_back(x);
                dfs(cur + 1, marked, skipped);
                marked.pop_back();
                skipped[x] = true;
            }
        }
    }
}

int main()
{
    ans = 0;
    cin >> n;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> m;
    vector<PII> cons(m);
    rep(i, m)
    {
        cin >> cons[i].first >> cons[i].second;
        cons[i].first--;
        cons[i].second--;
    }

    route.resize(m);
    rep(i, m)
    {
        route[i] = findpath(cons[i].first, cons[i].first, cons[i].second, {});
        sort(ALL(route[i]));
        //cerr << route[i].size() << endl;
        for (auto &&x : route[i])
        {
            //       cerr << x.first << "," << x.second << endl;
        }
    }
    dfs(0, {}, {});
    cout << ans << endl;
    return 0;
}