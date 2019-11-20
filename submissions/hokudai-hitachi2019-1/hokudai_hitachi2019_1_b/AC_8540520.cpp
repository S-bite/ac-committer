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
vector<int> actualOrderSum; //今までに注文された数の累積和
map<vector<int>, int> mmp;
vector<pair<int, int>> meanDistDistribute;
int maxTime;
int lastTime;
int v, e;
int curTime = 0;
int averageDist = 0;
class Item
{
public:
    int destination;
    int orderedTime;
    int id;

    Item(int destination, int orderedTime, int id) : destination(destination), orderedTime(orderedTime), id(id)
    {
    }
};
void genDeliverPathFromStackItem(vector<int> &deliverPath, map<int, vector<Item>> &deliverItem, vector<Item> &stackItem, int maxTime, int curTime, int deliverSize);
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
    rep(i, v)
    {
        averageDist += cost[0][i];
    }
    averageDist /= v;
    //cerr << v << " " << averageDist << endl;
}
template <typename T>
void dumpVector(vector<T> &v)
{
    for (auto x : v)
    {
        cerr << x << " ";
    }
    cerr << endl;
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

//peakTimeがtのとき、xで受けた注文の期待値を返す
ll f(int t, int x)
{

    if (x > lastTime)
    {
        return f(t, lastTime);
    }
    if (t < x)
    {

        return ((x * x) / (2 * t));
    }
    else
    {
        lld a = -1.0 / (lastTime - t);
        return (ll)(t / 2.0 + a * (x - t) * (x - t) / 2.0 + (x - t));
    }
}

int predict(vector<int> &s)
{
    if (s.size() <= 100)
    {
        return mt() % (lastTime);
    }
    int ret = 0;
    ll best = (1ll << 60);
    rep(i, 1, 10000)
    {
        ll cur = 0;
        rep(j, 200)
        {
            int r = mt() % (s.size());
            cur += ((ll)s[r] - (ll)f(i, r)) * ((ll)s[r] - (ll)f(i, r));
            assert(cur >= 0);
        }
        if (cur < best)
        {
            best = cur;
            ret = i;
        }
    }
    cerr << "best" << best << endl;
    return ret;
}

int predict1(vector<int> &s)
{
    if (s.size() < 500)
    {
        return -1;
    }
    int splitTime = s.size() / 2;
    lld slope = (lld)((s.back() - s[slope]) - (s[slope] - s[0]));
    int pPeakTime1 = mt() % lastTime + 1;
    //cerr << "slope:" << slope << endl;
    if (slope != 0.0)
    {
        pPeakTime1 = (int)((lld)splitTime * splitTime / slope);
        if (pPeakTime1 < 0)
            pPeakTime1 = 0;
        if (pPeakTime1 > lastTime)
            pPeakTime1 = lastTime;
    }
    return pPeakTime1;
}
int predict2(vector<int> &s)
{
    if (s.size() < 500)
    {
        return -1;
    }
    int pPeakTime2 = mt() % lastTime + 1;
    int pMax = -1;
    vector<int> d;
    int diff = s.size() / 50;
    rep(i, s.size() - diff)
    {
        if (s[i + diff] - s[i] > pMax)
        {
            pMax = s[i + diff] - s[i];
            pPeakTime2 = i;
        }
    }

    return pPeakTime2;
}

int twoOpt(vector<int> &stackItem)
{
    if (stackItem.size() <= 2)
    {
        return -1;
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
    rep(i, 10000)
    {
        int r1, r2;
        int width = 13;
        do
        {
            r1 = mt() % (stackItem.size() - 1);
            //r2 = mt() % (stackItem.size() - 1);
            r2 = r1 + mt() % width;
        } while (r2 >= stackItem.size() - 1 || r1 == r2);
        //cerr << r1 << " " << r2 << endl;
        if (r1 > r2)
        {
            swap(r1, r2);
        }
        int newscore = score;

        newscore -= cost[stackItem[r1]][stackItem[r1 + 1]];
        newscore -= cost[stackItem[r2]][stackItem[r2 + 1]];
        newscore += cost[stackItem[r1]][stackItem[r2]];
        newscore += cost[stackItem[r1 + 1]][stackItem[r2 + 1]];
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
    return score;
}

class State
{
public:
    int curTime;
    int maxTime;
    int curNode;
    int curDist; //curNodeからdeliverPath[curDeliverItemIndex]へ向かう辺を、何メートル進んでいるか？
    ll score;
    vector<int> deliverPath;            //商品を運ぶ道順(運ぶ順にソートされていて、最後は0（店）になっている)
    map<int, vector<Item>> deliverItem; // 現在運んでいる商品（deliverItem[i]でiのノードに運ぶ商品の配列）
    int curDeliverItemIndex = 0;
    vector<Item> stackItem; //店に置かれている商品(注文時間,目的地)
    vector<int> deliverNum; //i回目の配達は、deliverNum[i]>=stackItem.size()となったときに行われる
    int deliverNumIndex = 0;
    vector<int> output;
    State(int m) : maxTime(m)
    {
        curTime = 0;
        deliverPath.clear();
        curDeliverItemIndex = 0;
        stackItem.clear();
        curNode = 0;
        curDist = 0;
        score = 0;
        deliverNum.clear();
        deliverNumIndex = 0;
        output.clear();
    }
    void sync();
    void update();
};
void State::sync()
{
    int n;
    cin >> n;
    if (actualOrderSum.empty())
    {
        actualOrderSum.push_back(n);
    }
    else
    {
        actualOrderSum.push_back(actualOrderSum.back() + n);
    }
    if (n == 1)
    {
        int id, dist;
        cin >> id >> dist;
        dist--;
        Item item(dist, curTime, id);
        stackItem.push_back(item);
    }

    int m, t;
    cin >> m;
    rep(i, m)
    {
        cin >> t;
    }
}
void State::update()
{
    if (curNode == 0 && curDist == 0)
    {

        for (auto items : deliverItem)
        {
            for (auto item : items.second)
            {
                stackItem.push_back(item);
            }
        }
        deliverItem.clear();
        deliverPath.clear();
        if (!stackItem.empty())
        {

            if (deliverNumIndex >= deliverNum.size())
            {
                while (deliverNumIndex >= deliverNum.size())
                    deliverNum.push_back(deliverNum.back());
            }

            assert(deliverNum[deliverNumIndex] != 0);
            //assert(deliverItem.empty());
            genDeliverPathFromStackItem(deliverPath, deliverItem, stackItem, maxTime, curTime, deliverNum[deliverNumIndex]);

            curDeliverItemIndex = 0;
            assert(!deliverPath.empty());
        }
        else
        {
            output.push_back(-1);
            curTime++;
            return;
        }
    }
    //assert(g[curNode][deliverPath[curDeliverItemIndex]] != INF);
    output.push_back(deliverPath[curDeliverItemIndex] + 1);

    curDist++;
    curTime++;

    if (curDist == g[curNode][deliverPath[curDeliverItemIndex]])
    {
        deliverItem[curNode].clear();
        curNode = deliverPath[curDeliverItemIndex];
        for (auto item : deliverItem[curNode])
        {
            score += (ll)maxTime * maxTime - (ll)(curTime - item.orderedTime) * (curTime - item.orderedTime);
            //cerr << item.id << " " << curTime - item.orderedTime << endl;
        }

        curDeliverItemIndex++;
        curDist = 0;
        if (curDeliverItemIndex == deliverPath.size())
        {
            assert(curNode == 0);
            deliverPath.clear();
            deliverNumIndex++;
        }
    }
}

void calcGreedyCost(vector<int> &nodes, map<int, int> &greedyCost)
{
    //cerr << nodes.size() << endl;
    vector<int> tmp;
    int curNode = 0;

    map<int, bool> mp;
    rep(i, nodes.size() - 1)
    {
        int newNode = -1;
        rep(i, nodes.size() - 1)
        {
            if (mp[nodes[i]])
            {
                continue;
            }
            if (newNode == -1 || cost[curNode][nodes[i]] < cost[curNode][newNode])
            {
                newNode = nodes[i];
            }
        }
        if (newNode != -1)
        {
            tmp.push_back(newNode);
            mp[newNode] = true;
            curNode = newNode;
        }
    }
    curNode = 0;
    for (auto x : tmp)
    {
        if (curNode == 0)
            greedyCost[x] = cost[curNode][x];
        else
            greedyCost[x] = greedyCost[curNode] + cost[curNode][x];

        curNode = x;
    }
    //cerr << "ok" << endl;
}

//stackItemには、同じ番地が複数保存されていることもある（同じ場所が複数注文することがあるので）。なので、先に重複を潰してからtwoOptをする
void genDeliverPathFromStackItem(vector<int> &deliverPath, map<int, vector<Item>> &deliverItem, vector<Item> &stackItem, int maxTime, int curTime, int deliverSize)
{
    assert(deliverPath.empty());
    assert(stackItem.size() > 0);
    //stackItem.push_back(0);
    vector<int> tmp;
    map<int, int> mp;
    map<int, ll> weight;
    for (auto x : stackItem)
    {
        if (mp[x.destination] > 0)
        {
            mp[x.destination]++;
            continue;
        }
        mp[x.destination]++;

        tmp.push_back(x.destination);
    }
    map<int, int> greedyCost;
    calcGreedyCost(tmp, greedyCost);
    for (auto x : stackItem)
    {
        deliverItem[x.destination].push_back(x);
        weight[x.destination] += (ll)(maxTime * maxTime) - (ll)(curTime + greedyCost[x.destination] - x.orderedTime) * (curTime + greedyCost[x.destination] - x.orderedTime);
        //weight[x.destination] += (ll)(maxTime * maxTime) - (ll)(curTime + cost[0][x.destination] - x.orderedTime) * (curTime + cost[0][x.destination] - x.orderedTime);
    }
    vector<int> uniqueDestination;
    if (tmp.size() <= deliverSize)
    {
        uniqueDestination = tmp;
        uniqueDestination.push_back(0);
        stackItem.clear();
    }
    else
    {
        vector<pair<ll, int>> p;
        for (auto x : weight)
        {
            p.push_back({x.second, x.first});
        }
        sort(ALL(p), greater<pair<ll, int>>());
        map<int, bool> willDeliver;
        rep(i, deliverSize)
        {
            willDeliver[p[i].second] = true;
            uniqueDestination.push_back(p[i].second);
        }
        uniqueDestination.push_back(0);
        stackItem.clear();
        /*vector<Item> newStackItem;
        for (auto item : stackItem)
        {
            if (willDeliver[item.destination] == false)
            {
                newStackItem.push_back(item);
                //deliverItem[item.destination].clear();
            }
        }
        stackItem = newStackItem;
        //cerr << deliverSize << endl;
        */
    }
    int score = twoOpt(uniqueDestination);
    meanDistDistribute.push_back({uniqueDestination.size(), score});

    int curNode = 0;
    //map<int, bool> mp;
    mp.clear();
    for (auto x : uniqueDestination)
    {
        if (mp[x] == true && x != 0)
        {
            continue;
        }
        auto duringPath = path[curNode][x];
        deliverPath.insert(deliverPath.end(), path[curNode][x].begin() + 1, path[curNode][x].end());

        mp[x] = true;
        curNode = x;
    }

    //stackItem.clear();
}

vector<int> genVisitNum(int orderNum, vector<int> &orderSum)
{
    vector<int> ret;
    int diff = v / 2;
    rep(i, orderNum / diff)
    {
        ret.push_back(max(1, orderSum[(i + 1) * diff] - orderSum[(i)*diff]));
    }
    return ret;
}

int pickOrder(vector<int> &p, int psum)
{
    int r = mt() % psum;
    rep(i, p.size())
    {
        r -= p[i];
        if (r < 0)
            return i;
    }
    cerr << "something went wrong :(" << endl;
    return -1;
}

void genOrderNumAndSumFromPeakTime(int peakTime, int &orderNum, vector<int> &orderSum)
{
    orderNum = 0;
    orderSum.clear();
    rep(i, maxTime)
    {
        if (i < actualOrderSum.size())
        {
            orderSum[i] = actualOrderSum[i];
            orderNum = actualOrderSum[i];
            continue;
        }
        int t;
        if (i >= lastTime)
        {
            t = 0;
        }
        else
        {
            if (i <= peakTime)
            {
                t = ((mt() % peakTime) < i) ? 1 : 0;
            }
            else
            {
                t = ((mt() % (lastTime - peakTime)) < (lastTime - i)) ? 1 : 0;
            }
        }

        orderNum += t;
        if (i == 0)
        {
            orderSum[i] = t;
        }
        else
        {
            orderSum[i] = orderSum[i - 1] + t;
        }
    }
}

int main()
{
    actualOrderSum.push_back(0);
    clock_t starttime = clock();
    initGraph();
    vector<int> p(v, 0);
    rep(i, v)
    {
        cin >> p[i];
    }

    cin >> maxTime;

    lastTime = (maxTime * 95) / 100;

    vector<int> pseudoOrderSum(maxTime, 0);

    int pseudoOrderNum = 0;
    int pr = predict(actualOrderSum);

    cerr << actualOrderSum.size() << endl;
    genOrderNumAndSumFromPeakTime(pr, pseudoOrderNum, pseudoOrderSum);

    State state(maxTime);
    state.deliverNum = genVisitNum(pseudoOrderNum, pseudoOrderSum);
    //state.deliverNum.clear();
    //state.deliverNum.push_back(v * 11 / 20);
    bool f = false;
    while (state.curTime < maxTime)
    {
        state.sync();
        //cerr << "SYNC" << endl;
        if (state.curTime % 50 == 0 && double(clock() - starttime) / CLOCKS_PER_SEC < 27)
        {

            pr = predict(actualOrderSum);
            genOrderNumAndSumFromPeakTime(pr, pseudoOrderNum, pseudoOrderSum);
            state.deliverNum = genVisitNum(pseudoOrderNum, pseudoOrderSum);
            cerr << pr << endl;
        }
        state.update();
        cout << state.output.back() << endl;

        flush();
    }
    cerr << pr << endl;
    //   dumpVector(actualOrderSum);
    return 0;
}
