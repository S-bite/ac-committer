#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <iomanip>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> g;
    rep(i, n - 1)
    {
        int a, b, w;
        cin >> a >> b >> w;

        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    int ans[n + 1];
    map<int, bool> used;
    ans[1] = 0;
    queue<int> que;
    que.push(1);
    used[1] = true;
    while (!que.empty())
    {
        // cerr << que.size() << endl;
        int t = que.front();
        que.pop();
        for (auto x : g[t])
        {
            int b = x.first, w = x.second;
            if (used[b] == true)
            {
                continue;
            }
            if (w % 2 == 0)
            {
                ans[b] = ans[t];
            }
            else
            {
                ans[b] = 1 - ans[t];
            }
            used[b] = true;
            que.push(b);
        }
    }
    rep(i, 1, n + 1)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
