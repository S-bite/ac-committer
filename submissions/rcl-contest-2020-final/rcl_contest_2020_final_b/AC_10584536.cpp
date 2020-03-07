#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef pair<int, int> P;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int n, p, m;
int roboy, robox;
int curTurn = 0;
char dir[4] = {'U', 'L', 'D', 'R'};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

vector<vector<char>> tile;
vector<vector<bool>> wall;

std::random_device rnd;
std::mt19937 mt(rnd());

map<P, vector<P>> makeGraph(vector<vector<char>> &tilem, char mark)
{
    map<P, vector<P>> ret;
    rep(i, n) rep(j, n)
    {
        if (tile[i][j] != mark)
        {
            continue;
        }
        rep(k, n)
        {
            if (k != i && (tile[k][j] == mark || tile[k][j] == '@'))
            {
                ret[{i, j}].push_back({k, j});
            }
            if (k != j && (tile[i][k] == mark || tile[i][k] == '@'))
            {
                ret[{i, j}].push_back({i, k});
            }
        }
    }
    return ret;
}
class Tactics
{
public:
    map<P, bool> used;
    vector<P> order;
    int score;
    Tactics()
    {
        used.clear();
        order.clear();
        score = 0;
    }
    ~Tactics() {}
};
bool operator<(const Tactics &t1, const Tactics &t2)
{
    return t1.score < t2.score;
};

vector<P> makeLongestPath(map<P, vector<P>> &g, P start)
{
    vector<P> ret;
    Tactics t;
    t.order.push_back(start);
    priority_queue<Tactics> que;
    que.push(t);
    int cnt = 1;
    bool loop = true;
    bool change = true;
    int last = -1;
    while (change)
    {
        ret = que.top().order;
        change = false;
        priority_queue<Tactics> next;
        if (last == que.top().score)
            break;
        last = que.top().score;
        while (!que.empty())
        {
            Tactics cur = que.top();
            que.pop();
            for (auto x : g[cur.order.back()])
            {
                Tactics tt = cur;
                tt.order.push_back(x);
                if (tt.used[x] == false)
                {
                    tt.used[x] = true;
                    tt.score++;
                    change = true;
                }
                next.push(tt);
            }
        }
        int sss = (int)next.size();
        assert(que.size() == 0);
        if (sss == 0)
            break;
        rep(i, min(sss, 200))
        {
            que.push(next.top());
            next.pop();
        }
    }

    return ret;
}

bool isok(int ny, int nx)
{
}

bool isvalid(int y, int x)
{

    return 0 <= x && x < n && 0 <= y && y < n;
}
void move(P cur, P next)
{
    int dirInd;

    //cerr << cur.first << " " << next.first << " " << cur.second << " " << next.second << endl;
    assert(cur.first == next.first || cur.second == next.second);
    // ULDR
    if (cur.first == next.first)
    {
        if (cur.second < next.second)
        {
            dirInd = 3;
        }
        else
        {
            dirInd = 1;
        }
    }
    else
    {
        if (cur.first < next.first)
        {
            dirInd = 2;
        }
        else
        {
            dirInd = 0;
        }
    }
    int cy = cur.first;
    int cx = cur.second;
    int dist = max(abs(cur.first - next.first), abs(cur.second - next.second));
    map<P, bool> route;
    rep(i, dist + 1)
    {
        route[{cy + i * dy[dirInd], cx + i * dx[dirInd]}] = true;
    }
    rep(i, dist + 1)
    {
        if (wall[cy][cx])
        {
            int ny, nx;
            do
            {
                ny = mt() % n;
                nx = mt() % n;
            } while (wall[ny][nx] || route[{ny, nx}]);

            cout << "P " << cy << " " << cx << " " << ny << " " << nx << endl;
            wall[cy][cx] = false;
            wall[ny][nx] = true;

            curTurn++;
            if (curTurn == m)
                exit(0);
        }
        cy += dy[dirInd];
        cx += dx[dirInd];
    }
    //  assert(cy == next.first && cx == next.second);
    int ny = cy;
    int nx = cx;

    if (isvalid(ny, nx) && wall[ny][nx] == false)
    {
        rep(i, n) rep(j, n)
        {
            if (wall[i][j] == true)
            {
                cout << "P " << i << " " << j << " " << ny << " " << nx << endl;
                wall[i][j] = false;
                wall[ny][nx] = true;
                curTurn++;
                if (curTurn == m)
                    exit(0);
                i = n;
                break;
            }
        }
    }
    cout << dir[dirInd] << endl;
    roboy = next.first;
    robox = next.second;
    curTurn++;
    if (curTurn == m)
        exit(0);
}

void solve()
{
    int curTurn = 0;
    char curChar = tile[roboy][robox];

    while (curTurn < m)
    {
        auto g = makeGraph(tile, curChar);

        auto path = makeLongestPath(g, {roboy, robox});

        if (path.size() == 1)
            break;
        rep(i, 1, path.size())
        {
            move(path[i - 1], path[i]);
            assert(roboy == path[i].first && robox == path[i].second);
            tile[roboy][robox] = '@';
        }
        int ny = roboy, nx;
        do
        {
            //ny = mt() % n;
            nx = mt() % n;
        } while (tile[ny][nx] == '@');
        move({roboy, robox}, {ny, nx});
        curChar = tile[ny][nx];
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> p >> m;
    tile = vector<vector<char>>(n, vector<char>(n, '@'));
    wall = vector<vector<bool>>(n, vector<bool>(n, false));
    map<char, int> num;
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, n)
        {
            if (s[j] == 'x')
            {
                wall[i][j] = true;
            }
            if (s[j] == 'o')
            {
                roboy = i;
                robox = j;
            }
        }
    }
    rep(i, n) rep(j, n)
    {
        cin >> tile[i][j];
    }

    solve();
    return 0;
}
