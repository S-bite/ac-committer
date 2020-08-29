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

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> graph;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> group(n, -1);

    int num = 0;
    rep(i, n)
    {
        if (group[i] != -1)
        {
            continue;
        }
        deque<int> que;
        que.push_back(i);
        while (!que.empty())
        {
            int cur = que.front();
            que.pop_front();
            if (group[cur] != -1)
            {
                continue;
            }
            group[cur] = num;
            for (auto &&next : graph[cur])
            {
                if (group[next] == -1)
                    que.push_back(next);
            }
        }
        num++;
    }
    vector<int> gnum(n, 0);
    rep(i, n)
    {
        gnum[group[i]]++;
    }
    int ans = 0;
    rep(i, n)
    {
        chmax(ans, gnum[i]);
    }
    cout << ans << endl;
    return 0;
}