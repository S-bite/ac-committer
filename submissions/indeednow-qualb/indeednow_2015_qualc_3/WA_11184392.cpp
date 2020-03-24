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
    int n;
    cin >> n;
    map<int, vector<int>> g;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    map<int, bool> visited;
    priority_queue<int, vector<int>, greater<int>> pque;
    pque.push(1);
    vector<int> ans;
    while (!pque.empty())
    {
        int cur = pque.top();
        pque.pop();
        if (visited[cur] == true)
        {
            continue;
        }
        ans.push_back(cur);
        visited[cur] = true;
        for (auto x : g[cur])
        {
            if (visited[x] == false)
            {
                pque.push(x);
            }
        }
    }
    rep(i, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
