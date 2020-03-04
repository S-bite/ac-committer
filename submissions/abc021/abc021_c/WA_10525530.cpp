#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const int IINF = 1 << 29;
const int MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;
    int m;
    cin >> m;
    map<int, vector<int>> g;
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> num(n, 0);
    vector<int> dist(n, IINF);
    vector<bool> visited(n, false);
    deque<int> que;
    que.push_back(a);
    num[a] = 1;
    vector<bool> inque(n, false);
    inque[a] = true;

    while (!que.empty())
    {
        deque<int> nque;
        while (!que.empty())
        {
            int cur = que.front();
            que.pop_front();
            if (visited[cur])
                continue;
            visited[cur] = true;
            for (auto next : g[cur])
            {
                if (inque[next] == false)
                {
                    inque[next] = true;
                    nque.push_front(next);
                    cerr << next + 1 << " ";
                }
                if (visited[next] == false)
                {

                    num[next] += num[cur];
                }
            }
        }
        cerr << endl;
        que = nque;
        //visited = nvisited;
        cerr << que.size() << endl;
    }

    cout << num[b] << endl;
    return 0;
}
