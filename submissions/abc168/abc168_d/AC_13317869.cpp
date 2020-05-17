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

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> g;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    VI ans(n, -1);
    deque<PII> que;
    que.push_back({0, -2});
    while (!que.empty())
    {
        deque<PII> next;
        while (!que.empty())
        {
            auto cur = que.front().first;
            auto par = que.front().second;
            //cerr << par + 1 << "=>" << cur + 1 << endl;
            que.pop_front();
            if (ans[cur] != -1)
            {
                continue;
            }
            ans[cur] = par;
            for (auto &&x : g[cur])
            {
                next.push_back({x, cur});
            }
        }
        //cerr << "**" << endl;
        que = next;
    }
    cout << "Yes" << endl;
    rep(i, 1, n)
    {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}