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
    int dx[] = {1, 0, -1, 1, -1, 0};
    int dy[] = {1, 1, 1, 0, 0, -1};

    int n, x, y;
    cin >> n >> x >> y;
    map<PII, bool> blocked;

    map<PII, bool> visited;
    map<PII, int> ans;
    deque<PII> que;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        blocked[{a, b}] = true;
    }
    que.push_back({0, 0});
    int cur = 0;
    while (!que.empty())
    {
        deque<PII> next;
        while (!que.empty())
        {
            //cerr << visited.size() << endl;
            auto pos = que.front();
            que.pop_front();
            if (visited[pos] == true)
            {
                continue;
            }
            //cerr << pos.first << " " << pos.second << " " << ans[pos] << endl;

            visited[pos] = true;
            ans[pos] = cur;
            rep(i, 6)
            {
                int nx = pos.first + dx[i];
                int ny = pos.second + dy[i];
                if (nx < -202 || nx > 202 || ny < -202 || ny > 202 || blocked[{nx, ny}] || visited[{nx, ny}])
                    continue;
                next.push_back({nx, ny});
            }
        }
        cur++;
        que = next;
        if (visited[{x, y}])
            break;
    }
    if (visited[{x, y}] == false)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans[{x, y}] << endl;
    }
    return 0;
}
