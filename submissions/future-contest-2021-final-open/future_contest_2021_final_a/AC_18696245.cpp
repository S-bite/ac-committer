#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const int W = 50;
const int H = 50;
const int SIZE = 50;
int C;
struct State
{
    VVI grid;
    int score;
    double mine_coef;
    State(VVI &g, double cf)
    {
        score = 0;
        grid = g;
        mine_coef = cf;
    }

    int adjacent_count(int y, int x)
    {
        int adj_num = 0;
        if (y == 0)
            adj_num++;
        else
            adj_num += (grid[y - 1][x] == -1) ? 1 : 0;
        if (y == SIZE - 1)
            adj_num++;
        else
            adj_num += (grid[y + 1][x] == -1) ? 1 : 0;
        if (x == 0)
            adj_num++;
        else
            adj_num += (grid[y][x - 1] == -1) ? 1 : 0;
        if (x == SIZE - 1)
            adj_num++;
        else
            adj_num += (grid[y][x + 1] == -1) ? 1 : 0;
        return adj_num;
    }
    void mine(int y, int x)
    {
        //必ず4方向のうちどれかが採掘済み
        assert(adjacent_count(y, x) != 0);
        //指定したグリッドがまだ採掘されていない
        assert(grid[y][x] != -1);
        score += grid[y][x] - C / adjacent_count(y, x);
        grid[y][x] = -1;
    }
    int mine_cost(int y, int x)
    {
        return grid[y][x] - C / adjacent_count(y, x);
    }
    double weighted_profit(int y, int x)
    {
        double ret = 0;
        rep(i, SIZE) rep(j, SIZE)
        {
            if (grid[i][j] == -1)
                continue;
            //ret += grid[y][x] / (fabs(i - y) + fabs(j - x));
            //ret = max(ret, (double)grid[i][j] / (max(0.01, fabs(i - y) + fabs(j - x))));
            ret = max(ret, (double)grid[i][j] - (double)C * mine_coef * (fabs(i - y) + fabs(j - x)));
        }
        // cerr << "ret " << ret << endl;
        return ret;
    }
};

pair<int, vector<pair<int, int>>> solve(VVI grid, double mine_coef)
{
    auto sim = State(grid, mine_coef);
    priority_queue<tuple<int, int, int>> pque;
    rep(i, SIZE)
    {
        pque.push({sim.grid[0][i] + sim.weighted_profit(0, i) - sim.mine_cost(0, i), 0, i});
        pque.push({sim.grid[SIZE - 1][0] + sim.weighted_profit(SIZE - 1, i) - sim.mine_cost(SIZE - 1, i), SIZE - 1, i});
        pque.push({sim.grid[i][0] + sim.weighted_profit(i, 0) - sim.mine_cost(i, 0), i, 0});
        pque.push({sim.grid[i][SIZE - 1] + sim.weighted_profit(i, SIZE - 1) - sim.mine_cost(i, SIZE - 1), i, SIZE - 1});
    }
    VI score;
    vector<pair<int, int>> move;
    while (!pque.empty())
    {
        auto profit = get<0>(pque.top());
        auto y = get<1>(pque.top());
        auto x = get<2>(pque.top());
        pque.pop();
        //cerr << sim.score << endl;
        if (sim.grid[y][x] == -1)
        {
            continue;
        }
        sim.mine(y, x);
        move.push_back({y, x});
        score.push_back(sim.score);
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        rep(i, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || SIZE - 1 < nx || ny < 0 || SIZE - 1 < ny || sim.grid[ny][nx] == -1)
            {
                continue;
            }
            pque.push({sim.grid[ny][nx] + 1.4 * sim.weighted_profit(ny, nx) - sim.mine_cost(ny, nx), ny, nx});
        }
    }
    int best_score = 0;
    int best_idx = -1;
    vector<PII> ret;
    rep(i, score.size())
    {
        if (best_score < score[i])
        {
            best_score = score[i];
            best_idx = i;
        }
    }
    rep(i, best_idx + 1)
    {
        ret.push_back({move[i].first, move[i].second});
    }
    auto r = make_pair(best_score, ret);
    return r;
}

int main()
{
    VVI grid(H, VI(W, 0));
    cin >> C;
    rep(i, H) rep(j, W)
    {
        cin >> grid[i][j];
    }
    vector<PII> ans;
    int best_score = -IINF;
    double best_coef;
    double max_coef = 0.66;
    double min_coef = 0.25;
    int div_num = 20;
    rep(i, div_num)
    {
        auto ret = solve(grid, min_coef + (max_coef - min_coef) / (double)(div_num - 1) * (double)i);
        if (ret.first > best_score)
        {
            best_score = ret.first;
            ans = ret.second;
            best_coef = min_coef + (max_coef - min_coef) / (double)(div_num - 1) * (double)i;
        }
    }
    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a.first << " " << a.second << endl;
    }
    cerr << "best score : " << best_score << endl;
    cerr << "best coef  : " << best_coef << endl;
    return 0;
}
