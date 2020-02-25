#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> g;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    deque<int> que;
    que.push_back(1);
    rep(i, 2)
    {
        deque<int> next;
        while (!que.empty())
        {
            auto cur = que.front();
            que.pop_front();
            for (auto x : g[cur])
            {
                next.push_back(x);
            }
        }
        que = next;
    }
    for (auto x : que)
    {
        if (x == n)
        {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
