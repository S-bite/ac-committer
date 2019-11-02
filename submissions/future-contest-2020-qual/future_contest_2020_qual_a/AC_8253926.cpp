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
    int trappedRobotNum = 0;
};
bool isvalid(int y, int x)
{

    return 0 <= y && y < n && 0 <= x && x < n;
}

/*
void fillsign(vector<vector<char>> &signs, vector<vector<bool>> &blocks, int y, int x, char c)
{
    signs[y][x] = c;
    if (isvalid(y + 1, x) && blocks[y + 1][x] == false && signs[y + 1][x] == ' ')
    {
        fillsign(signs, blocks, y + 1, x, 'U');
    }

    if (isvalid(y - 1, x) && blocks[y - 1][x] == false && signs[y - 1][x] == ' ')
    {
        fillsign(signs, blocks, y - 1, x, 'D');
    }
    if (isvalid(y, x + 1) && blocks[y][x + 1] == false && signs[y][x + 1] == ' ')
    {
        fillsign(signs, blocks, y, x + 1, 'L');
    }
    if (isvalid(y, x - 1) && blocks[y][x - 1] == false && signs[y][x - 1] == ' ')
    {
        fillsign(signs, blocks, y, x - 1, 'R');
    }
}*/
void fillsign(vector<vector<char>> &signs, vector<vector<bool>> &blocks, int y, int x, char c)
{
    deque<vector<int>> que;
    que.push_back({y, x, c});

    while (!que.empty())
    {
        int y = que.front()[0];
        int x = que.front()[1];
        char c = (char)que.front()[2];
        que.pop_front();
        if (signs[y][x] == ' ')
        {
            signs[y][x] = c;
        }
        else
        {
            continue;
        }
        if (blocks[(y + 1 + n) % n][x] == false && signs[(y + 1 + n) % n][x] == ' ')
        {
            que.push_back({(y + 1 + n) % n, x, 'U'});
        }
        if (blocks[(y - 1 + n) % n][x] == false && signs[(y - 1 + n) % n][x] == ' ')
        {
            que.push_back({(y - 1 + n) % n, x, 'D'});
        }
        if (blocks[y][(x + 1 + n) % n] == false && signs[y][(x + 1 + n) % n] == ' ')
        {
            que.push_back({y, (x + 1 + n) % n, 'L'});
        }
        if (blocks[y][(x - 1 + n) % n] == false && signs[y][(x - 1 + n) % n] == ' ')
        {
            que.push_back({y, (x - 1 + n) % n, 'R'});
        }
    }
}
void init(Answer &ans)
{
    ans.signnum = 0;
    rep(i, n)
    {
        vector<char> tmp;
        rep(j, n)
        {
            tmp.push_back(' ');
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
void eval(vector<Robot> robots, vector<vector<bool>> &blocks, int gy, int gx, Answer &ans, int limit)
{
    auto signs = ans.signs;
    ans.trappedRobotNum = 0;
    int ret = 0;
    ret -= 10 * ans.signnum;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (auto robot : robots)
    {
        rep(i, n * n)
        {
            if (visited[robot.y][robot.x] == false)
            {
                visited[robot.y][robot.x] = true;
                ret += 1;
            }
            if (robot.y == gy && robot.x == gx)
            {
                ret += 1000;
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
                ans.trappedRobotNum++;
                if (limit < ans.trappedRobotNum)
                {
                    ans.score = -1000;
                    return;
                }
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
    clock_t starttime = clock();
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

    rep(i, b)
    {
        int y, x;
        cin >> y >> x;
        blocks[y][x] = true;
    }
    Answer ans;
    init(ans);
    fillsign(ans.signs, blocks, gy, gx, '@');
    ans.signs[gy][gx] = ' ';
    rep(i, n) rep(j, n)
    {
        if (ans.signs[i][j] != ' ')
            ans.signnum++;
    }
    eval(robots, blocks, gy, gx, ans, 101);
    Answer newans = ans;
    int cnt = 0;
    while ((double(clock() - starttime) / CLOCKS_PER_SEC < 2.9))
    {
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
            if (mt() % 5 == 0)
            {
                newans.signs[ry][rx] = angles[mt() % 4];
            }
            else
            {
                newans.signs[ry][rx] = ' ';
                newans.signnum--;
            }
        }
        eval(robots, blocks, gy, gx, newans, newans.trappedRobotNum);
        if (ans.score < newans.score)
        {
            ans.signs[ry][rx] = newans.signs[ry][rx];
            ans.score = newans.score;
            ans.signnum = newans.signnum;
            // cerr << cnt << endl;
        }
        else
        {
            newans.signs[ry][rx] = ans.signs[ry][rx];
            newans.score = ans.score;
            newans.signnum = ans.signnum;
        }
        cnt++;
    }

    rep(i, n) rep(j, n)
    {
        int ry = i, rx = j;
        if (newans.signs[ry][rx] == ' ' || mt() % 2 == 0)
            continue;
        newans.signs[ry][rx] = ' ';
        newans.signnum--;
        eval(robots, blocks, gy, gx, newans, newans.trappedRobotNum);
        if (ans.score < newans.score)
        {
            ans.signs[ry][rx] = newans.signs[ry][rx];
            ans.score = newans.score;
            ans.signnum = newans.signnum;
            // cerr << cnt << endl;
            //cerr << cnt << endl;
        }
        else
        {
            newans.signs[ry][rx] = ans.signs[ry][rx];
            newans.score = ans.score;
            newans.signnum = ans.signnum;
        }
        cnt++;
    }
    printans(ans);
    cerr << ans.score << " " << cnt << endl;
    return 0;
}
