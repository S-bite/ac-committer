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
#define INF 1 << 29
using namespace std;
int maxTime;
int v, e;
int curTime = 0;

void warshallfloyd(vector<vector<int>> &g, vector<vector<int>> &cost, vector<vector<vector<int>>> &path)
{
    int v = g.size();
    rep(i, v) rep(j, v)
    {
        cost[i][j] = g[i][j];
        if (cost[i][j] != INF && cost[i][j] != 0)
        {
            path[i][j].push_back(i);
            path[i][j].push_back(j);
        }
    }
    rep(i, v)
    {
        path[i][i].push_back(i);
    }
    rep(k, v) rep(i, v) rep(j, v)
    {
        if (cost[i][j] > cost[i][k] + cost[k][j])
        {
            cost[i][j] = cost[i][k] + cost[k][j];
            path[i][j] = path[i][k];
            path[i][j].insert(path[i][j].end(), path[k][j].begin() + 1, path[k][j].end());
        }
    }
}

void dumpShortestPathInfo(vector<vector<vector<int>>> &path, vector<vector<int>> &cost)
{
    int v = path.size();
    rep(i, v)
    {
        cout << 1 << "->" << i + 1 << " : ";
        for (auto x : path[0][i])
        {
            cout << x + 1 << " ";
        }
        cout << " (" << cost[0][i] << ")" << endl;
    }
}

void deliver(deque<int> &que, vector<vector<vector<int>>> &path, vector<vector<int>> &cost)
{
    int curPos = 0;
    int curTarget;
    map<int, bool> visited;
    while (!que.empty())
    {
        curTarget = que.front();
        que.pop_front();
        if (visited[curTarget])
            continue;
        for (auto x : path[curPos][curTarget])
        {
            rep(i, cost[curPos][x])
            {
                cout << x + 1 << endl;
                curTime++;
                if (curTime == maxTime)
                    exit(0);
            }
            curPos = x;
            visited[curPos] = true;
        }
    }
    for (auto x : path[curPos][0])
    {
        rep(i, cost[curPos][x])
        {
            cout << x + 1 << endl;
            curTime++;
            if (curTime == maxTime)
                exit(0);
        }
        curPos = x;
    }
}

int main()
{
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, INF));
    vector<vector<int>> cost(v, vector<int>(v, INF));

    vector<vector<vector<int>>> path(v, vector<vector<int>>(v));

    rep(i, e)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a][b] = c;
        g[b][a] = c;
    }
    rep(i, v)
    {
        g[i][i] = 0;
    }
    warshallfloyd(g, cost, path);
    cin >> maxTime;
    vector<pair<int, int>> orders(maxTime, {-1, -1});
    int orderIndex = 0;

    rep(i, maxTime)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            cin >> orders[orderIndex].first >> orders[orderIndex].second;
            orders[orderIndex].first--;
            orders[orderIndex].second--;
            orderIndex++;
        }
    }
    deque<int> que;
    orderIndex = 0;

    while (true)
    {
        while (orders[orderIndex].first != -1 && orders[orderIndex].first <= curTime)
        {
            que.push_back(orders[orderIndex].second);
            orderIndex++;
        }
        if (que.empty())
        {
            cout << -1 << endl;
            curTime++;
            if (curTime == maxTime)
                exit(0);
        }
        else
        {
            deliver(que, path, cost);
        }
    }
    return 0;
}