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

void dfs(map<int, int> &chara, map<int, vector<int>> &g, int start)
{
    map<int, int> visited;
    deque<pair<int, int>> que;
    que.push_back({start, 0});
    while (!que.empty())
    {
        auto cur = que.front();
        que.pop_front();
        if (visited[cur.first])
            continue;
        chara[cur.first] = cur.second;
        visited[cur.first] = true;
        for (auto x : g[cur.first])
        {
            if (visited[x] == false)
            {
                que.push_back({x, cur.second + 1});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<int, vector<int>> g;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    map<int, int> fennec, snuke;
    dfs(fennec, g, 0);
    dfs(snuke, g, n - 1);
    int fnum = 0, snum = 0;
    rep(i, n)
    {

        if (fennec[i] <= snuke[i])
        {
            fnum++;
        }
        else
        {
            snum++;
        }
    }
    if (fnum > snum)
    {
        cout << "Fennec" << endl;
    }
    else
    {
        cout << "Snuke" << endl;
    }

    return 0;
}
