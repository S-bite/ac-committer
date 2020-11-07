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
    stack<int> card;
};
State state;

map<int, pair<int, int>> pos;

void init()
{
    state.grid = vector<vector<int>>(N, vector<int>(N, -1));
    rep(i, M)
    {
        int x, y;
        cin >> y >> x;
        state.grid[y][x] = i;
        pos[i] = { y, x };
    }
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
        points.push_back(pos[i]);
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
    cerr << rec(dist, cost, parent, num, 1, 0) << endl;
    ;
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

void move(int target)
{
    assert(pos[target].first != IINF);
    while (pos[target].first > state.y) {
        cout << "D";
        state.y++;
    }
    while (pos[target].first < state.y) {
        cout << "U";
        state.y--;
    }
    while (pos[target].second > state.x) {
        cout << "R";
        state.x++;
    }
    while (pos[target].second < state.x) {
        cout << "L";
        state.x--;
    }
}

void move(pair<int, int> target)
{
    while (target.first > state.y) {
        cout << "D";
        state.y++;
    }
    while (target.first < state.y) {
        cout << "U";
        state.y--;
    }
    while (target.second > state.x) {
        cout << "R";
        state.x++;
    }
    while (target.second < state.x) {
        cout << "L";
        state.x--;
    }
}

void I()
{
    assert(state.grid[state.y][state.x] != -1);
    state.card.push(state.grid[state.y][state.x]);
    pos[state.grid[state.y][state.x]] = { IINF, IINF };
    state.grid[state.y][state.x] = -1;
    cout << "I";
}
void O()
{
    assert(state.grid[state.y][state.x] == -1);
    assert(!state.card.empty());
    state.grid[state.y][state.x] = state.card.top();
    pos[state.card.top()] = { state.y, state.x };
    state.card.pop();
    cout << "O";
}

void pickup(vector<int>& targets)
{
    for (auto&& target : targets) {
        move(target);
        I();
    }
}

void vomit(int num)
{
    assert(state.grid[state.y][state.x] == -1);
    O();
    vector<pair<int, int>> points = { { state.y, state.x } };
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
        move(newp);
        O();
        points.push_back(newp);
    }
}

void relax(int start, int num)
{
    vomit(num);
    for (int i = start; i < start + num; i++) {
        move(i);
        I();
    }
}

int main()
{
    init();
    rep(i, 10)
    {
        auto ret = TSP(i * 10, 10);
        pickup(ret);
        relax(i * 10, 10);
    }
    cout << endl;

    return 0;
}