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

int main()
{
    int h, w;
    cin >> h >> w;
    map<char, vector<pair<int, int>>> tele;
    vector<string> g;
    g.push_back(string(w + 2, '#'));
    cerr << g.back() << endl;
    rep(i, h)
    {
        string t;
        cin >> t;
        g.push_back("#" + t + "#");
    }
    g.push_back(string(w + 2, '#'));
    h += 2;
    w += 2;
    assert(g.size() == h);
    assert(g[0].size() == w);

    pair<int, int> start, goal;
    rep(i, h) rep(j, w)
    {
        //   cerr << i << " " << j << " " << g[i][j] << endl;
        if (g[i][j] == '#') {
            continue;
        } else if (g[i][j] == '.') {
            continue;
        } else if (g[i][j] == 'S') {
            start = { i, j };
        } else if (g[i][j] == 'G') {
            goal = { i, j };
        } else {
            tele[g[i][j]].push_back({ i, j });
        }
    }
    deque<pair<int, pair<int, int>>> que;
    vector<vector<bool>> enqued(h, vector<bool>(w, false));
    vector<vector<int>> ans(h, vector<int>(w, IINF));
    map<char, bool> usedcol;
    //cerr << que.size() << endl;

    que.push_back({ 0, start });
    while (!que.empty()) {
        //cerr << que.size() << endl;
        int cost = que.front().first;
        pair<int, int> pos = que.front().second;
        que.pop_front();
        if (ans[pos.first][pos.second] <= cost)
            continue;
        ans[pos.first][pos.second] = cost;
        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };
        rep(i, 4)
        {
            pair<int, int> next = { pos.first + dy[i], pos.second + dx[i] };
            if (next.first < 0 || next.first >= h || next.second < 0 || next.second >= w || g[next.first][next.second] == '#')
                continue;
            if (enqued[next.first][next.second] == false) {
                enqued[next.first][next.second] = true;
                que.push_back({ cost + 1, next });
            }
        }
        if (usedcol[g[pos.first][pos.second]] == false) {
            for (auto&& next : tele[g[pos.first][pos.second]]) {
                if (enqued[next.first][next.second] == false) {
                    enqued[next.first][next.second] = true;
                    que.push_back({ cost + 1, next });
                }
            }
            usedcol[g[pos.first][pos.second]] = true;
        }
    }
    if (ans[goal.first][goal.second] == IINF) {
        cout << -1 << endl;
    } else {
        cout << ans[goal.first][goal.second] << endl;
    }
    return 0;
}
