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

int n, k;
map<PII, bool> visited;

vector<PII> calcEffect(VVI &board, int y, int x, int color, vector<PII> &log)
{
    deque<PII> que;
    if (log.empty())
    {
        que.push_back({y, x});
    }
    else
    {
        for (auto e : log)
        {
            que.push_back(e);
            visited[e] = false;
        }
    }
    log.clear();
    VI num(10, 0);
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!que.empty())
    {
        //cerr << 123 << endl;
        auto cur = que.front();
        que.pop_front();
        if (visited[cur])
            continue;
        visited[cur] = true;
        int cy = cur.first;
        int cx = cur.second;
        int cc = board[cy][cx];
        if (cc != color)
        {
            log.push_back({cy, cx});
            num[cc]++;
            continue;
        }
        rep(i, 4)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (0 <= ny && ny < n && 0 <= nx && nx < n)
            {
                que.push_back({ny, nx});
            }
        }
    }
    //cerr << 456 << endl;
    vector<PII> ret;
    rep(i, 1, 10)
    {
        //  cerr << i << " " << num[i] << endl;
        ret.push_back({num[i], i});
    }
    sort(ALL(ret));
    return ret;
}

void paint(VVI &board, int y, int x, int newCol, int oldCol, vector<PII> &log)
{
    for (auto &&g : log)
    {
        if (board[g.first][g.second] == oldCol)
            board[g.first][g.second] = newCol;
    }
}

void print(vector<tuple<int, int, int>> &ans)
{
    cout << ans.size() << endl;
    rep(i, ans.size())
    {
        int y, x, col;
        tie(y, x, col) = ans[i];
        cout << y + 1 << " " << x + 1 << " " << col << endl;
    }
}

int eval(VVI &board)
{
    VI num(10, 0);
    rep(i, n) rep(j, n) num[board[i][j]]++;
    return *max_element(ALL(num));
}

int test(VVI board, int y, int x)
{
    visited.clear();
    int cost = 0;
    vector<PII> log;
    int color = board[y][x];
    rep(i, n * n)
    {
        cost = i + 1;

        auto ret = calcEffect(board, y, x, color, log);
        //cerr << ret.back().first << endl;
        if (ret.back().first == 0)
        {
            break;
        }

        paint(board, y, x, ret.back().second, color, log);
        color = ret.back().second;
    }
    return n * n * 100 - cost;
}

int main()
{
    int id;
    cin >> id >> n >> k;
    VVI board(n, VI(n, -1));
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, n)
        {

            board[i][j] = s[j] - '0';
        }
    }
    vector<tuple<int, int, int>> ans;

    int y = n / 2, x = n / 2, score = test(board, y, x);
    int sz = 13;
    rep(dx, sz) rep(dy, sz)
    {
        // cerr << dy << " " << dx << endl;
        int i = n / 2 - sz + 2 * dy;
        int j = n / 2 - sz + 2 * dx;
        int cur = test(board, i, j);
        if (cur > score)
        {
            score = cur;
            y = i;
            x = j;
        }
        //cerr << score << endl;
    }
    visited.clear();

    vector<PII> log;
    int color = board[y][x];

    rep(i, n * n)
    {
        auto ret = calcEffect(board, y, x, color, log);
        //cerr << log.size() << endl;
        //cerr << ret.back().first << endl;
        if (ret.back().first == 0)
        {
            break;
        }
        ans.push_back({y, x, ret.back().second});
        paint(board, y, x, ret.back().second, color, log);
        color = ret.back().second;
    }
    print(ans);
    return 0;
}
