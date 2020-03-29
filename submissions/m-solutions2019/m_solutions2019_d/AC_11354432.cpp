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
map<int, vector<int>> g;
int main(int argc, char const *argv[])
{
    int n;
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
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    sort(ALL(c), greater<int>());
    ll ans = 0;
    deque<int> que;
    que.push_back(0);
    map<int, bool> visited;
    int index = 0;
    vector<int> num(n, 0);

    while (!que.empty())
    {
        int cur = que.front();
        que.pop_front();
        if (visited[cur])
            continue;
        visited[cur] = true;
        num[cur] = c[index];
        index++;
        for (auto x : g[cur])
        {
            que.push_back(x);
        }
    }
    rep(i, n)
    {
        for (auto x : g[i])
        {
            if (x > i)
            {
                ans += min(num[i], num[x]);
            }
        }
    }
    cout << ans << endl;
    rep(i, n)
    {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
