#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (int)(b); ++i)
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

int ans = IINF;

bool check(vector<vector<bool>> &connect, vector<int> &cur, int target)
{
    for (auto v : cur)
    {
        if (connect[v][target] == false)
        {
            return false;
        }
    }
    return true;
}
int n, m;
void rec(vector<vector<bool>> &connect, vector<bool> used, int cans)
{

    VVI cur(1, VI(0));
    vector<PII> deg;

    rep(i, n)
    {
        if (used[i] == false)
        {
            used[i] = true;
            cur[0].push_back(i);
            break;
        }
    }
    if (cur[0].empty())
    {
        chmin(ans, cans);
        return;
    }
    cans++;
    rec(connect, used, cans);
    rep(i, n)
    {
        if (used[i])
        {
            continue;
        }
        bool ok = false;
        rep(j, cur.size())
        {
            if (check(connect, cur[j], i))
            {
                cur[j].push_back(i);
                ok = true;
            }
        }
        if (ok == false && connect[cur[0][0]][i] == true)
        {
            cur.push_back({});
            cur.back().push_back(i);
            cur.back().push_back(cur[0][0]);
        }
    }
    int b = -1, idx = -1;
    rep(i, cur.size())
    {
        assert((int)cur[i].size() > 0);
        if (b < (int)cur[i].size())
        {
            b = (int)cur[i].size();
            idx = i;
        }
    }
    cur.push_back({cur[0][0]});
    //cerr << b << " " << idx << endl;
    rep(i, cur.size())
    {

        for (auto x : cur[i])
        {
            used[x] = true;
        }
        rec(connect, used, cans);
        for (auto x : cur[i])
        {
            used[x] = false;
        }
    }
}

int main()
{

    cin >> n >> m;
    vector<vector<bool>> connect(n, vector<bool>(n, false));
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        connect[a][b] = true;
        connect[b][a] = true;
    }
    vector<bool> used(n, false);
    rec(connect, used, 0);
    cout << ans << endl;
    return 0;
}