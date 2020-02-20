#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> g;
    rep(i, m)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int l;
            cin >> l;
            l--;
            g[l].push_back(n + i);
            g[n + i].push_back(l);
        }
    }
    vector<bool> visited(n + m, false);
    deque<int> que;
    que.push_back(0);
    while (!que.empty())
    {
        int cur = que.front();
        que.pop_front();
        if (visited[cur])
            continue;
        visited[cur] = true;
        for (auto x : g[cur])
        {
            if (visited[x] == false)
            {
                que.push_front(x);
            }
        }
    }
    bool ok = true;
    rep(i, n, n + m)
    {
        ok &= visited[i];
    }
    if (ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
