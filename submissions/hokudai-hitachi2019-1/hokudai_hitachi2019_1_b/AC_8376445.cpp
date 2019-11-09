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
vector<vector<int>> g;
vector<vector<int>> cost;
vector<vector<vector<int>>> path;

void genDeliverPathFromStackItem(vector<int> &deliverPath, vector<int> &stackItem)
{
    assert(deliverPath.empty());
    stackItem.push_back(0);
    int curNode = 0;
    map<int, bool> mp;
    for (auto x : stackItem)
    {
        //assert(mp[0] == false);
        if (mp[x] == true && x != 0)
            continue;
        auto duringPath = path[curNode][x];
        deliverPath.insert(deliverPath.end(), path[curNode][x].begin() + 1, path[curNode][x].end());
        mp[x] = true;
        curNode = x;
    }
}

class State
{
public:
    int curTime;
    int maxTime;
    int curNode;
    int curDist;             //curNodeからdeliverPath[curDeliverItemIndex]へ向かう辺を、何メートル進んでいるか？
    vector<int> deliverPath; //商品を運ぶ道順(運ぶ順にソートされていて、最後は0（店）になっている)
    int curDeliverItemIndex = 0;
    vector<int> stackItem; //店に置かれている商品
    State(int m) : maxTime(m)
    {
        curTime = 0;
        deliverPath.clear();
        curDeliverItemIndex = 0;
        stackItem.clear();
        curNode = 0;
        curDist = 0;
    }
    void sync()
    {
        int n, id, dst = -1;
        cin >> n;

        if (n != 0)
        {
            cin >> id >> dst;
            dst--;
            stackItem.push_back(dst);
        }
        cerr << "dst" << dst << endl;
        int m, t;
        cin >> m;
        rep(i, m)
        {
            cin >> t;
        }
    }
    void flush()
    {
        string ret;
        cin >> ret;
        assert(ret == "OK");
        int n, t;
        cin >> n;
        rep(i, n)
        {
            cin >> t;
        }
    }

    void update()
    {
        if (deliverPath.empty())
        {
            if (stackItem.empty())
            {
                cout << -1 << endl;
                curTime++;
                return;
            }
            else
            {
                genDeliverPathFromStackItem(deliverPath, stackItem);
                curDeliverItemIndex = 0;
            }
        }
        if (deliverPath[curDeliverItemIndex] == curNode)
        {
            curDeliverItemIndex++;
        }
        cout << deliverPath[curDeliverItemIndex] + 1 << endl;
        curDist++;
        //cerr << curNode << "," << deliverPath[curDeliverItemIndex] << endl;
        assert(g[curNode][deliverPath[curDeliverItemIndex]] != INF);
        if (curDist == g[curNode][deliverPath[curDeliverItemIndex]])
        {
            curNode = deliverPath[curDeliverItemIndex];
            curDist = 0;
            if (curDeliverItemIndex + 1 == deliverPath.size())
            {
                deliverPath.clear();
            }
        }
        curTime++;
    }
};

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

void initGraph()
{
    cin >> v >> e;
    g = vector<vector<int>>(v, vector<int>(v, INF));
    cost = vector<vector<int>>(v, vector<int>(v, INF));
    path = vector<vector<vector<int>>>(v, vector<vector<int>>(v));
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
}

int main()
{
    initGraph();
    cerr << path[0][1].size() << endl;

    vector<int> f(v, 0);
    rep(i, v)
    {
        cin >> f[i];
    }

    cin >> maxTime;
    State state(maxTime);
    while (state.curTime < maxTime)
    {

        state.sync();
        state.update();

        state.flush();
    }
    return 0;
}