#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
int N = 20;
int M = 100;
typedef struct Pos Pos;
struct Pos {
    int y, x;
};

typedef struct State State;
struct State {
    vector<vector<int>> grid;
    int x, y;
    int pena;
    string ans;
    int start;
    stack<int> card;
    map<int, pair<int, int>> pos;
    bool operator<(const State& rhs) const
    {
        return pena > rhs.pena;
    }
};
State state;

void init()
{
    state.grid = vector<vector<int>>(N, vector<int>(N, -1));
    rep(i, M)
    {
        int x, y;
        cin >> y >> x;
        state.grid[y][x] = i;
        state.pos[i] = { y, x };
    }
    state.pena = 0;
    state.ans = "";
}

int rec(vector<vector<int>>& dist, vector<vector<int>>& cost, vector<vector<int>>& par, int num, int visited, int cur)
{
    if (cost[visited][cur] >= 0) {
        return cost[visited][cur];
    }
    if (visited == (1 << num) - 1) {
        cost[visited][cur] = 0;
        return 0;
    }
    int ans = IINF;
    for (int i = 0; i < num; i++) {
        if ((visited >> i) & 1) {
            continue;
        }
        int tmp = rec(dist, cost, par, num, visited | 1 << i, i) + dist[cur][i];
        if (tmp < ans) {
            ans = tmp;
            par[visited][cur] = i;
        }
    }
    //cerr << visited << " " << cur << " " << par[visited][cur] << endl;
    cost[visited][cur] = ans;
    return ans;
}

vector<int> TSP(int start, int num)
{

    vector<pair<int, int>> points;
    points.push_back({ state.y, state.x });
    for (int i = start; i < start + num; i++) {
        points.push_back(state.pos[i]);
    }
    num++;
    assert(num == points.size());
    vector<vector<int>> dist(num, vector<int>(num, 0));
    vector<vector<int>> cost(1 << (num), vector<int>(num, -1));
    vector<vector<int>> parent(1 << (num), vector<int>(num, 0));

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {

            dist[i][j] = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
        }
    }
    rec(dist, cost, parent, num, 1, 0);
    int idx = 0;
    int visited = 1;
    vector<int> ans;
    for (int i = 1; i < num; i++) {

        idx = parent[visited][idx];
        visited |= 1 << idx;
        ans.push_back(idx - 1 + start);
        //cerr << idx << endl;
    }
    return ans;
}

void I()
{
    assert(state.grid[state.y][state.x] != -1);
    state.card.push(state.grid[state.y][state.x]);
    state.pos[state.grid[state.y][state.x]] = { IINF, IINF };
    state.grid[state.y][state.x] = -1;
    state.ans += "I";
}
void O()
{
    //cout << state.grid[state.y][state.x] << endl;
    assert(state.grid[state.y][state.x] == -1);
    assert(!state.card.empty());
    state.grid[state.y][state.x] = state.card.top();
    state.pos[state.card.top()] = { state.y, state.x };
    state.card.pop();
    state.ans += "O";
}

int findInsideCard(pair<int, int> target)
{
    return -1;
    int yhigh = max(target.first, state.y);
    int ylow = min(target.first, state.y);
    int xhigh = max(target.second, state.x);
    int xlow = min(target.second, state.x);
    int ret = -1;
    int dist = IINF;

    rep(i, M)
    {
        if (state.pos[i].first == IINF)
            continue;
        if (state.pos[i] == target) {
            continue;
        }
        if (state.pos[i].first == state.y && state.pos[i].second == state.x) {
            continue;
        }

        if (ylow <= state.pos[i].first && state.pos[i].first <= yhigh && xlow <= state.pos[i].second && state.pos[i].second <= xhigh) {
            int curdist = abs(state.pos[i].first - state.y) + abs(state.pos[i].second - state.x);
            if (curdist < dist) {
                ret = i;
                dist = curdist;
            }
        }
    }
    return ret;
}

void moveRobotSub(pair<int, int> target, bool isSwipe)
{
    assert(target.first != IINF);
    while (target.first > state.y) {
        bool pickOtherCard = false;

        if (isSwipe && state.y + 1 < N && state.grid[state.y][state.x] != -1 && state.grid[state.y + 1][state.x] == -1 && state.y < N / 2) {
            I();
            pickOtherCard = true;
        }

        state.ans += "D";
        state.pena++;

        state.y++;
        if (pickOtherCard) {
            O();
        }
    }
    while (target.first < state.y) {
        bool pickOtherCard = false;
        if (isSwipe && state.y - 1 >= 0 && state.grid[state.y][state.x] != -1 && state.grid[state.y - 1][state.x] == -1 && state.y > N / 2) {
            I();
            pickOtherCard = true;
        }
        state.ans += "U";

        state.pena++;
        state.y--;
        if (pickOtherCard) {
            O();
        }
    }
    while (target.second > state.x) {
        bool pickOtherCard = false;
        if (isSwipe && state.x + 1 < N && state.grid[state.y][state.x] != -1 && state.grid[state.y][state.x + 1] == -1 && state.x < N / 2) {
            I();
            pickOtherCard = true;
        }

        state.ans += "R";

        state.pena++;
        state.x++;
        if (pickOtherCard) {
            O();
        }
    }
    while (target.second < state.x) {
        bool pickOtherCard = false;
        if (isSwipe && state.x - 1 >= 0 && state.grid[state.y][state.x] != -1 && state.grid[state.y][state.x - 1] == -1 && state.x > N / 2) {
            I();
            pickOtherCard = true;
        }

        state.ans += "L";

        state.pena++;
        state.x--;
        if (pickOtherCard) {
            O();
        }
    }
    //cout << "fin" << endl;
}
void moveRobotSub(int target, bool isSwipe)
{
    moveRobotSub(state.pos[target], isSwipe);
}

void moveRobot(pair<int, int> target, bool isSwipe)
{
    if (isSwipe == false) {
        moveRobotSub(target, false);
        return;
    }
    while (int t = findInsideCard(target)) {
        if (t == -1) {
            break;
        }
        moveRobotSub(t, true);
    }
    moveRobotSub(target, true);
}

void moveRobot(int target, bool isSwipe)
{
    moveRobot(state.pos[target], isSwipe);
}

void pickup(vector<int>& targets)
{
    for (auto&& target : targets) {
        moveRobot(target, true);
        //cerr << "bacl" << endl;
        I();
    }
}

vector<int> seekStack(stack<int> st, int num)
{

    vector<int> ret;
    rep(i, num)
    {
        assert(!st.empty());
        ret.push_back(st.top());
        st.pop();
    }
    return ret;
}

void vomit(int num)
{
    assert(state.grid[state.y][state.x] == -1);
    vector<pair<int, int>> points = { { state.y, state.x } };

    auto cards = seekStack(state.card, num);
    map<pair<int, int>, bool> reserved;
    reserved[{ state.y, state.x }] = true;
    rep(i, num - 1)
    {
        pair<int, int> newp;
        int dist = IINF;
        rep(y, N)
        {
            rep(x, N)
            {
                if (state.grid[y][x] != -1)
                    continue;
                if (reserved[{ y, x }]) {
                    continue;
                }
                int curdist = 0;
                for (auto&& p : points) {
                    curdist += abs(p.first - y) + abs(p.second - x);
                }
                if (curdist < dist) {
                    newp = { y, x };
                    dist = curdist;
                }
            }
        }
        reserved[newp] = true;
        points.push_back(newp);
    }
    sort(ALL(points));
    sort(ALL(cards),greater<int>());
    map<int, pair<int, int>> pos;
    rep(i, cards.size())
    {
        pos[cards[i]] = points[i];
    }
    rep(i, num)
    {
        auto newp = pos[state.card.top()];
        //cerr << state.card.top() << " " << newp.first << " " << newp.second << endl;
        moveRobot(newp, false);
        O();
    }
    // cerr << 123 << endl;
    //cerr << 456 << endl;
}

bool isValid(stack<int> st)
{
    if (st.empty()) {
        return true;
    }
    int cur = st.top();
    st.pop();
    while (!st.empty()) {
        if (cur != st.top() + 1) {
            return false;
        }
        cur = st.top();
        st.pop();
    }
    return true;
}

void relax(int start, int num)
{
    if (isValid(state.card)) {
        return;
    }
    vomit(num);
    for (int i = start; i < start + num; i++) {
        moveRobot(i, false);
        I();
    }
}

void greedy(int start, int num)
{
    map<int, bool> visited;
    rep(_, num)
    {
        int target;
        int dist = IINF;
        for (int i = start; i < start + num; i++) {
            if (visited[i])
                continue;
            int curdist = abs(state.pos[i].first - state.y) + abs(state.pos[i].second - state.x);
            if (curdist < dist) {
                target = i;
                dist = curdist;
            }
        }
        visited[target] = true;
        moveRobot(target, false);
        I();
    }
    relax(start, num);
}

State eval_TSP(int num)
{
    auto oldState = state;
    int rem = M - state.start;
    auto order = TSP(state.start, min(num, rem));
    pickup(order);
    relax(state.start, min(num, rem));
    state.start += num;
    auto ret = state;
    state = oldState;
    return ret;
}
State eval_greedy(int num)
{
    auto oldState = state;
    int rem = M - state.start;
    greedy(state.start, min(num, rem));
    state.start += num;
    auto ret = state;
    state = oldState;
    return ret;
}

int main()
{
    init();
    priority_queue<State> pque[M + 1];
    pque[0].push(state);
    int B = 2;

    rep(i, M)
    {
        cerr << i << endl;
        int C = 0;
        while (!pque[i].empty() && C < B) {
            state = pque[i].top();
            for (int num = 1; num < 8; num++) {
                auto cur = eval_TSP(num);
                chmin(cur.start, M);
                pque[cur.start].push(cur);
            }

            for (int num = 1; num <= 32; num++) {
                auto cur = eval_greedy(num);
                chmin(cur.start, M);
                pque[cur.start].push(cur);
            }
            pque[i].pop();
            C++;
        }
    }

    state = pque[M].top();
    cout << state.ans << endl;
    assert(isValid(state.card));
    cerr << "score:" << 4000 - state.pena << endl;
    return 0;
}