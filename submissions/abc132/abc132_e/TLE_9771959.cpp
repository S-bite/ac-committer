#include <bits/stdc++.h>
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
const ll INF = (1ll << 60);
const int IINF = (1 << 30);

vector<int> dijkstra(map<int, vector<int>> &g, int n, int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    map<int, bool> used;
    pque.push({0, s});
    vector<int> ret(n, IINF);
    while (!pque.empty())
    {
        int cost = pque.top().first;
        int cur = pque.top().second;
        pque.pop();
        if (used[cur])
        {
            continue;
        }
        used[cur] = true;
        ret[cur] = cost;
        for (auto x : g[cur])
        {
            pque.push({cost + 1, x});
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
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
        //g[b].push_back(a);
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    if (m == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    map<int, vector<int>> h;
    rep(i, n)
    {
        deque<int> que;
        que.push_back(i);
        rep(j, 3)
        {
            map<int, bool> pushed;
            deque<int> next;
            next.clear();
            //cerr << "loop " << j << endl;
            while (!que.empty())
            {
                int cur = que.front();
                //   cerr << cur << endl;

                que.pop_front();
                for (auto x : g[cur])
                {
                    if (pushed[x])
                    {
                        continue;
                    }
                    pushed[x] = true;
                    next.push_back(x);
                }
            }
            que = next;
        }
        while (!que.empty())
        {
            cerr << i << " " << que.front() << endl;
            h[i].push_back(que.front());
            que.pop_front();
        }
    }
    cerr << "ok" << endl;
    auto dist = dijkstra(h, n, s);
    if (dist[t] == IINF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[t] << endl;
    }

    return 0;
}
