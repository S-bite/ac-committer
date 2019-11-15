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
random_device rnd;
mt19937 mt(0);
vector<vector<int>> g;
vector<vector<int>> cost;
vector<vector<vector<int>>> path;
vector<int> cumulativeOrderedNum; //今までに注文された数の累積和
map<vector<int>, int> mmp;

int maxTime;
int v, e;
int curTime = 0;

void dumpVector(vector<int> &v)
{
    for (auto x : v)
    {
        cerr << x << " ";
    }
    cerr << endl;
}

void twoOpt(vector<int> &stackItem)
{
    if (stackItem.size() <= 2)
    {
        return;
    }
    vector<int> tmp;
    int curNode = 0;

    map<int, bool> mp;
    rep(i, stackItem.size() - 1)
    {
        int newNode = -1;
        rep(i, stackItem.size() - 1)
        {
            if (mp[stackItem[i]])
            {
                continue;
            }
            if (newNode == -1 || cost[curNode][stackItem[i]] < cost[curNode][newNode])
            {
                newNode = stackItem[i];
            }
        }
        if (newNode != -1)
        {
            tmp.push_back(newNode);
            mp[newNode] = true;
            curNode = newNode;
        }
    }
    tmp.push_back(0);
    stackItem = tmp;
    //dumpVector(stackItem);
    int score = 0;
    curNode = 0;
    rep(i, stackItem.size())
    {
        score += cost[curNode][stackItem[i]];
        curNode = stackItem[i];
    }
    rep(i, 100000)
    {
        int r1, r2;
        do
        {
            r1 = mt() % (stackItem.size() - 1);
            r2 = mt() % (stackItem.size() - 1);
        } while (r1 == r2);
        if (r1 > r2)
        {
            swap(r1, r2);
        }
        int newscore = score;

        newscore -= cost[stackItem[r1]][stackItem[r1 + 1]];
        newscore -= cost[stackItem[r2]][stackItem[r2 + 1]];
        newscore += cost[stackItem[r1]][stackItem[r2]];
        newscore += cost[stackItem[r1 + 1]][stackItem[r2 + 1]];
        //cerr << score - newscore << endl;
        /*
        assert(stackItem[r1] != stackItem[r2]);
        assert(stackItem[r1 + 1] != stackItem[r2 + 1]);
        assert(cost[stackItem[r1]][stackItem[r1 + 1]] > 0);
        assert(cost[stackItem[r2]][stackItem[r2 + 1]] > 0);
        assert(cost[stackItem[r1]][stackItem[r2]] > 0);
        assert(cost[stackItem[r1 + 1]][stackItem[r2 + 1]] > 0);
        */
        if (newscore < score)
        {
            //cerr << r1 << " " << r2 << endl;
            reverse(stackItem.begin() + r1 + 1, stackItem.begin() + r2 + 1);
            score = newscore;
            //dumpVector(stackItem);
        }
    }

    int t = 0;
    curNode = 0;
    rep(i, stackItem.size())
    {
        t += cost[curNode][stackItem[i]];
        assert(cost[curNode][stackItem[i]] == cost[stackItem[i]][curNode]);
        curNode = stackItem[i];
    }
    //cerr << tmp << " " << score << " " << t << endl;
    assert(t == score);
    //cerr << tmp << "->" << score << endl;
}

//stackItemには、同じ番地が複数保存されていることもある（同じ場所が複数注文することがあるので）。なので、先に重複を潰す
int estimateDeliverTime(vector<int> &stackItem)
{
    if (stackItem.empty())
    {
        return 0;
    }
    vector<int> tmp;
    map<int, bool> mp;
    for (auto x : stackItem)
    {
        if (mp[x])
        {
            continue;
        }
        mp[x] = true;
        tmp.push_back(x);
    }
    //if (mmp[tmp] != 0)
    //    return mmp[tmp];
    twoOpt(tmp);
    int score = 0;
    int curNode = 0;
    for (auto x : tmp)
    {
        score += cost[curNode][x];
        curNode = x;
    }
    //mmp[tmp] = score;
    return score;
}

vector<int> genAllVisitPath(vector<pair<int, int>> &v)
{
    //vから同じ頂点を省いたもの
    vector<int> uniqueNode;
    map<int, bool> mp;
    for (auto x : v)
    {
        if (mp[x.second])
            continue;
        mp[x.second] = true;
        uniqueNode.push_back(x.second);
    }
    vector<int> ret;
    int curNode = 0;
    mp.clear();
    rep(i, uniqueNode.size() - 1)
    {
        int newNode = -1;
        rep(i, uniqueNode.size() - 1)
        {
            if (mp[uniqueNode[i]])
            {
                continue;
            }
            if (newNode == -1 || cost[curNode][uniqueNode[i]] < cost[curNode][newNode])
            {
                newNode = uniqueNode[i];
            }
        }
        if (newNode != -1)
        {
            ret.push_back(newNode);
            mp[newNode] = true;
            curNode = newNode;
        }
    }
    twoOpt(ret);
    return ret;
}
//stackItemには、同じ番地が複数保存されていることもある（同じ場所が複数注文することがあるので）。なので、先に重複を潰してからtwoOptをする
void genDeliverPathFromStackItem(vector<int> &deliverPath, vector<pair<int, int>> &stackItem, int maxTime, int curTime)
{
    assert(deliverPath.empty());
    assert(stackItem.size() > 0);
    //stackItem.push_back(0);
    vector<int> tmp;
    vector<int> greedyPath = genAllVisitPath(stackItem);
    map<int, int> greedyCost;
    int curNode = 0;
    int prevCostSum = 0;
    for (auto x : greedyPath)
    {
        greedyCost[x] = prevCostSum + cost[curNode][x];
        prevCostSum = greedyCost[x];
        curNode = x;
    }

    map<int, ll> weight; //目的地に対する訪れるべき度
    for (auto t : stackItem)
    {

        if (weight[t.second] == 0)
        {
            tmp.push_back(t.second);
        }
        //最速で届けた場合に得られる点数
        //if (curTime + greedyCost[t.second] >= maxTime)
        //    weight[t.second] += 1;
        //else
        weight[t.second] += maxTime * maxTime - (curTime + greedyCost[t.second] - t.first) * (curTime + greedyCost[t.second] - t.first);
        // cerr << weight[t.second] << endl;
        assert(weight[t.second] > 0);
    }
    vector<int> deliverItem;
    int deliverLimit = v / 2;
    //dumpVector(tmp);
    if (weight.size() <= deliverLimit)
    {
        deliverItem = tmp;
        deliverItem.push_back(0);
        stackItem.clear();
        twoOpt(deliverItem);
    }
    else
    {

        deliverItem.push_back(0);
        vector<pair<int, int>> ttmp = stackItem;
        stackItem.clear();
        vector<pair<ll, int>> p;
        for (auto x : tmp)
        {
            p.push_back({weight[x], x});
        }
        stackItem.clear();
        map<int, bool> notDeliver;
        sort(ALL(p), greater<pair<int, int>>());
        rep(i, p.size())
        {
            if (i <= deliverLimit)
            {
                deliverItem.push_back(p[i].second);
            }
            else
            {
                notDeliver[p[i].second] = true;
            }
        }
        rep(i, ttmp.size())
        {
            if (notDeliver[ttmp[i].second])
            {
                stackItem.push_back(ttmp[i]);
            }
        }
        deliverItem.push_back(0);

        twoOpt(deliverItem);
    }
    curNode = 0;
    map<int, bool> mp;
    mp.clear();
    for (auto x : deliverItem)
    {
        if (mp[x] == true && x != 0)
            continue;
        auto duringPath = path[curNode][x];
        deliverPath.insert(deliverPath.end(), path[curNode][x].begin() + 1, path[curNode][x].end());
        mp[x] = true;
        curNode = x;
    }
    //stackItem.clear();
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
    vector<pair<int, int>> stackItem; //店に置かれている商品(注文時間,目的地)
    State(int m) : maxTime(m)
    {
        curTime = 0;
        deliverPath.clear();
        curDeliverItemIndex = 0;
        stackItem.clear();
        curNode = 0;
        curDist = 0;
    }
    void sync(int n, int dst)
    {
        if (n == 0)
        {
            return;
        }
        stackItem.push_back({curTime, dst});
    }
    void update()
    {
        if (deliverPath.empty())
        {
            if (!stackItem.empty())
            {
                genDeliverPathFromStackItem(deliverPath, stackItem, maxTime, curTime);
                curDeliverItemIndex = 0;
            }

            if (stackItem.empty())
            {

                cout << -1 << endl;
                curTime++;
                return;
            }
        }
        if (deliverPath[curDeliverItemIndex] == curNode)
        {
            curDeliverItemIndex++;
        }
        cout << deliverPath[curDeliverItemIndex] + 1 << endl;
        curDist++;
        //cerr << curNode << "," << deliverPath[curDeliverItemIndex] << endl;
        //cerr << g[curNode][deliverPath[curDeliverItemIndex]] << endl;
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

void dumpGraph(vector<vector<int>> &g)
{
    cout << v << " " << e << endl;
    rep(i, v)
    {
        rep(j, v)
        {
            if (g[i][j] != INF)
            {
                cout << i << " " << j << " " << g[i][j] << endl;
            }
        }
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
    cin >> maxTime;
    vector<pair<int, int>> orders;
    cumulativeOrderedNum = vector<int>(maxTime, 0);
    rep(i, maxTime)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int id, dst;
            cin >> id >> dst;
            dst--;
            orders.push_back({t, dst});
        }
        else
        {
            orders.push_back({0, -1});
        }
        if (i == 0)
        {
            cumulativeOrderedNum[i] = t;
        }
        else
        {
            cumulativeOrderedNum[i] = cumulativeOrderedNum[i - 1] + t;
        }
    }
    State state(maxTime);
    while (state.curTime < maxTime)
    {
        state.sync(orders[state.curTime].first, orders[state.curTime].second);
        state.update();
    }
    //cerr<<"Ordered:"<<orders.size()<<", deliverd"<<orders.size()-state.stackItem.size()-state.
    return 0;
}
