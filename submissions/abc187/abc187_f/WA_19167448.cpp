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

int main()
{
    int n, m;
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
    int ans = 0;
    vector<bool> used(n, false);
    while (true)
    {
        vector<int> cur;
        vector<PII> deg;
        rep(i, n)
        {
            int d = 0;
            rep(j, n)
            {
                if (used[j] == false && connect[i][j] == true)
                {
                    d++;
                }
            }
            deg.push_back({d, i});
        }
        sort(ALL(deg));

        rep(t, n)
        {
            int i = deg[t].second;
            if (used[i] == false)
            {
                used[i] = true;
                cur.push_back(i);
                break;
            }
        }
        if (cur.empty())
        {
            break;
        }
        ans++;
        rep(t, n)
        {
            int i = deg[t].second;
            if (used[i])
            {
                continue;
            }
            if (check(connect, cur, i))
            {
                cur.push_back(i);
                used[i] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}