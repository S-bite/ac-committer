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
const int IINF = 1 << 28;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
map<int, vector<int>> g;
vector<vector<PII>> route;
vector<vector<vector<PII>>> path;
int n;
int m;
int tmpnum = 0;
int tmpsize = 0;

ll ans;
int start;
ll K;
map<int, bool> cc;
vector<vector<vector<PII>>> warshallfloyd()
{
    vector<vector<vector<PII>>> path(n, vector<vector<PII>>(n, vector<PII>(0)));
    VVI dist(n, VI(n, IINF));
    rep(i, n)
    {
        for (auto &&j : g[i])
        {
            if (i < j)
            {
                path[i][j].push_back({i, j});
                path[j][i].push_back({i, j});
                dist[i][j] = 1;
                dist[j][i] = 1;
            }
        }
    }
    rep(k, n) rep(i, n) rep(j, n)
    {
        if (dist[i][j] > dist[i][k] + dist[k][j])
        {
            dist[i][j] = dist[i][k] + dist[k][j];
            path[i][j] = path[i][k];
            for (auto x : path[k][j])
                path[i][j].push_back(x);
            path[j][i] = path[i][j];
        }
    }
    return path;
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

void dfs(int cur, vector<PII> &marked, map<PII, bool> &skipped)
{
    if (cur == m)
    {
        int num = 0;
        //  cerr << "*************" << endl;
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
        //  cerr << endl;
        for (auto &&x : marked)
        {
            //       cerr << x.first << "," << x.second << " ";
        }
        //  cerr << endl;
        //  cerr << n - 1 - marked.size() - num << endl;
        assert(n - 1 >= marked.size() + num);
        ans += K * powll(2, n - 1 - marked.size() - num - tmpsize);
        return;
    }
    else
    {
        if (cc[cur])
        {
            dfs(cur + 1, marked, skipped);
            return;
        }
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
        vector<PII> pii;

        if (flag == false)
        {
            for (auto &&x : route[cur])
            {
                if (skipped[x])
                    continue;
                marked.push_back(x);
                dfs(cur + 1, marked, skipped);
                marked.pop_back();
                skipped[x] = true;
                pii.push_back(x);
            }
        }
        for (auto &&x : pii)
            skipped[x] = false;
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
    auto path = warshallfloyd();
    cin >> m;
    vector<PII> cons(m);
    rep(i, m)
    {
        cin >> cons[i].first >> cons[i].second;
        cons[i].first--;
        cons[i].second--;
    }

    route.resize(m);
    map<PII, int> num;
    rep(i, m)
    {
        start = i;
        route[i] = path[cons[i].first][cons[i].second];
        //sort(ALL(route[i]));
        //cerr << route[i].size() << endl;
        for (auto &&x : route[i])
        {
            num[x]++;
            //       cerr << x.first << "," << x.second << endl;
        }
    }

    K = 1;
    int wrapnum = 0;
    int tmptmp = 0;
    rep(i, m)
    {
        cc[i] = true;
        for (auto &&x : route[i])
        {
            chmax(tmptmp, (int)route[i].size());
            if (num[x] > 1)
            {
                wrapnum++;
                cc[i] = false;
                break;
            }
        }
        if (cc[i])
        {
            K *= powll(2, route[i].size()) - 1;
            tmpnum++;
            tmpsize += route[i].size();
        }
    }
    cerr << "calc"
         << tmpnum << " " << tmptmp << endl;
    if (tmpnum != 0 || tmptmp < 15)
    {
        rep(i, m)
        {
            random_shuffle(ALL(route[i]));
        }
    }
    map<PII, bool> skipped = {};
    vector<PII> marked = {};
    if (tmpnum == m)
    {
        cerr << "tmp" << endl;
        ans = K * powll(2, n - 1 - tmpsize);
    }
    else
    {
        dfs(0, marked, skipped);
    }
    cout << ans << endl;
    return 0;
}
