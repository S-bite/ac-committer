#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
class state
{
  public:
    int grid[20][20];
    int m = 1000;
    void init();
    void rotate(int, int, int);
    void show();
    void eval();
    int score;
};
void state::init()
{
    rep(i, 20) rep(j, 20) cin >> grid[i][j];
}
void state::rotate(int y, int x, int s)
{
    rep(i, s / 2) rep(j, (s + 1) / 2)
    {
        int first = grid[y + i][x + j];
        grid[y + i][x + j] = grid[y + s - 1 - j][x + i];
        grid[y + s - 1 - j][x + i] = grid[y + s - 1 - i][x + s - 1 - j];
        grid[y + s - 1 - i][x + s - 1 - j] = grid[y + j][x + s - 1 - i];
        grid[y + j][x + s - 1 - i] = first;
    }
}
void state::show()
{
    rep(i, 20)
    {
        rep(j, 20)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
void state::eval()
{
    int ret = 0;
    int h = 10;
    rep(i, 10) rep(j, 10)
    {
        if (grid[i][j] == 0)
            ret += 100;
        if (grid[i][j] == 1)
            ret -= abs(9 - j);
        if (grid[i][j] == 2)
            ret -= abs(9 - i);
        if (grid[i][j] == 3)
            ret -= abs(9 - j) + abs(9 - i);
    }
    rep(i, 10) rep(j, 10, 20)
    {
        if (grid[i][j] == 1)
            ret += 100;
        if (grid[i][j] == 0)
            ret -= abs(10 - j);
        if (grid[i][j] == 3)
            ret -= abs(9 - i);
        if (grid[i][j] == 2)
            ret -= abs(10 - j) + abs(9 - i);
    }
    rep(i, 10, 20) rep(j, 10)
    {
        if (grid[i][j] == 2)
            ret += 100;
        if (grid[i][j] == 3)
            ret -= abs(9 - j);
        if (grid[i][j] == 0)
            ret -= abs(10 - i);
        if (grid[i][j] == 1)
            ret -= abs(9 - j) + abs(10 - i);
    }
    rep(i, 10, 20) rep(j, 10, 20)
    {
        if (grid[i][j] == 3)
            ret += 100;
        if (grid[i][j] == 2)
            ret -= abs(10 - j);
        if (grid[i][j] == 1)
            ret -= abs(10 - i);
        if (grid[i][j] == 0)
            ret -= abs(10 - j) + abs(10 - i);
    }
    score = ret;
}

int main(int argc, char const *argv[])
{
    random_device rnd;
    mt19937 mt(rnd());
    int _;
    cin >> _ >> _;
    state s;
    s.init();
    s.eval();
    int cnt = 0;
    while (s.m > 0)
    {
        int by, bx, bs, bscore = s.score;
        clock_t start = clock();

        rep(i, 1000) //while ((double)(clock() - start) / CLOCKS_PER_SEC * 1000.0 < 1900.0 / 1000.0)
        {

            cnt++;
            state _s = s;

            int ry, rx, rs;
            do
            {
                ry = mt() % 19;
                rx = mt() % 19;
                rs = mt() % (20 - max(ry, rx)) + 1;
            } while (max(ry + rs, rx + rs) > 20);
            _s.rotate(ry, rx, rs);
            _s.eval();
            if (_s.score > bscore)
            {
                by = ry;
                bx = rx;
                bs = rs;
                bscore = _s.score;
            }
        }
        s.rotate(by, bx, bs);
        cout << by << " " << bx << " " << bs << endl;
        //dumpl(cnt);
        s.m--;
        if (bscore == 20 * 20)
            break;
    }

    return 0;
}
