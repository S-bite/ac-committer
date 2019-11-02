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
int n, m, b;
char angles[4] = {'U', 'D', 'R', 'L'};

random_device rnd;
mt19937 mt(0);
struct Robot
{
    int y, x;
    char angle;
};

struct Answer
{
    vector<vector<char>> signs;
    int signnum;
    int score;
};

void init(Answer &ans)
{
    ans.signnum = 0;
    rep(i, n)
    {
        vector<char> tmp;
        rep(j, n)
        {
            if (mt() % 10 == 0)
            {
                tmp.push_back(angles[mt() % 4]);
                ans.signnum++;
            }
            else
            {
                tmp.push_back(' ');
            }
        }
        ans.signs.push_back(tmp);
    }
}

void getdiff(int &dy, int &dx, char angle)
{
    if (angle == 'U')
    {
        dy = -1;
        dx = 0;
    }
    else if (angle == 'D')
    {
        dy = 1;
        dx = 0;
    }
    else if (angle == 'R')
    {
        dy = 0;
        dx = 1;
    }
    else if (angle == 'L')
    {
        dy = 0;
        dx = -1;
    }
}

void eval(vector<Robot> robots, vector<vector<bool>> &blocks, int gy, int gx, Answer &ans)
{
    auto signs = ans.signs;
    int ret = 0;
    ret -= 10 * ans.signnum;
    for (auto robot : robots)
    {
        rep(i, n * n)
        {
            if (robot.y == gy && robot.x == gx)
            {
                ret += 1000;
                cerr << "yay!" << endl;
                break;
            }
            if (signs[robot.y][robot.x] != ' ')
            {
                robot.angle = signs[robot.y][robot.x];
            }
            int dy, dx, newy, newx;

            getdiff(dy, dx, robot.angle);
            newy = (robot.y + n + dy) % n;
            newx = (robot.x + n + dx) % n;
            if (blocks[newy][newx] == true)
            {
                break;
            }
            robot.y = newy;
            robot.x = newx;
        }
    }
    ans.score = ret;
}

void printans(Answer &ans)
{
    cout << ans.signnum << endl;
    rep(i, n) rep(j, n)
    {
        if (ans.signs[i][j] != ' ')
        {
            cout << i << " " << j << " " << ans.signs[i][j] << endl;
        }
    }
}
int main(int argc, char const *argv[])
{
    int gy, gx;
    cin >> n >> m >> b;
    cin >> gy >> gx;
    vector<Robot> robots(m);
    vector<vector<bool>> blocks(n, vector<bool>(n, false));
    rep(i, m)
    {
        cin >> robots[i].y >> robots[i].x >> robots[i].angle;
        //cerr << robots[i].angle << endl;
    }

    rep(i, m)
    {
        int y, x;
        cin >> y >> x;
        blocks[y][x] = true;
    }
    Answer ans;
    init(ans);
    eval(robots, blocks, gy, gx, ans);
    rep(i, 3000)
    {
        Answer newans = ans;
        int ry, rx;
        do
        {
            ry = mt() % n;
            rx = mt() % n;
        } while (blocks[ry][rx] == true);

        if (newans.signs[ry][rx] == ' ')
        {
            newans.signs[ry][rx] = angles[mt() % 4];
            newans.signnum++;
        }
        else
        {
            newans.signs[ry][rx] = ' ';
            newans.signnum--;
        }
        eval(robots, blocks, gy, gx, newans);
        if (ans.score < newans.score)
        {
            ans = newans;
        }
    }
    printans(ans);
    cerr << ans.score << endl;
    return 0;
}
