#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
std::random_device rnd;
std::mt19937 mt(rnd());

class Tactics
{
public:
    int score;
    vector<vector<int>> order;

    Tactics()
    {
    }
    ~Tactics() {}
};
bool operator<(const Tactics &t1, const Tactics &t2)
{
    return t1.score < t2.score;
};

bool is_valid(int y, int x)
{
    return (0 <= y && y < 50 && 0 <= x && x < 50);
}

void eval(Tactics &tact, vector<vector<int>> &pict)
{
    int n = 50;
    int m = 500;

    //udlr
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    tact.score = 0;
    vector<vector<int>> g(50, vector<int>(50, -1));
    g[0][0] = 0;
    g[0][n - 1] = 1;
    g[n - 1][0] = 2;
    g[n - 1][n - 1] = 3;

    rep(i, m)
    {
        int col = i % 4;
        int y = tact.order[i][0];
        int x = tact.order[i][1];
        int dir = tact.order[i][2];
        assert(g[y][x] == i % 4);
        rep(j, 1, 6)
        {
            int ny = y + j * dy[dir];
            int nx = x + j * dx[dir];

            if (is_valid(ny, nx))
            {
                g[ny][nx] = col;
            }
        }
    }
    rep(i, 50)
    {
        rep(j, 50)
        {
            if (g[i][j] == pict[i][j])
            {
                tact.score++;
            }
        }
    }
}

void print(vector<vector<int>> &g)
{
    int n = 50;
    rep(i, n)
    {
        rep(j, n)
        {
            if (g[i][j] == -1)
            {
                cerr << ".";
            }
            else
            {
                cerr << g[i][j];
            }
        }
        cerr << endl;
    }
}

void genTactics(Tactics &tact)
{
    int m = 500;
    int n = 50;
    vector<vector<int>> g(50, vector<int>(50, -1));
    vector<vector<int>> paintable;
    g[0][0] = 0;
    g[0][n - 1] = 1;
    g[n - 1][0] = 2;
    g[n - 1][n - 1] = 3;
    paintable.push_back({0, 0});
    paintable.push_back({0, n - 1});
    paintable.push_back({n - 1, 0});
    paintable.push_back({n - 1, n - 1});
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    rep(i, m)
    {
        //cerr << i << endl;

        //print(g);
        //cerr << "---------------------------------------------" << endl;
        int r;
        int py;
        int px;
        int col;
        do
        {
            r = mt() % paintable.size();
            py = paintable[r][0];
            px = paintable[r][1];
            col = g[py][px];
        } while (col != i % 4);
        assert(g[py][px] == i % 4);
        int dir = mt() % 4;
        tact.order.push_back({py, px, dir});
        rep(j, 1, 6)
        {
            int ny = py + j * dy[dir];
            int nx = px + j * dx[dir];
            if (is_valid(ny, nx))
            {
                if (g[ny][nx] == -1)
                {
                    paintable.push_back({ny, nx});
                }
                g[ny][nx] = col;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    clock_t starttime = clock();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pict(n, vector<int>(n, 0));
    rep(i, n) rep(j, n) cin >> pict[i][j];
    priority_queue<Tactics> pque;
    rep(_, 1000)
    {

        Tactics t;
        genTactics(t);
        eval(t, pict);
        pque.push(t);
    }

    auto best = pque.top();
    rep(i, m)
    {
        cout << best.order[i][0] << " " << best.order[i][1] << " "
             << "UDLR"[best.order[i][2]] << endl;
    }
    //cerr << "loop num:" << cnt << endl;
    cerr << "score:" << best.score << endl;

    return 0;
}
