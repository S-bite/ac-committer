#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;
map<int, vector<int>> g;
map<int, int> color;
int red = 0;
int blue = 0;

void dfs(int cur, int par, int col)
{
    color[cur] = col;
    if (col == 0)
        red++;
    else
        blue++;
    for (auto x : g[cur])
    {
        if (x != par)
        {
            dfs(x, cur, (col + 1) % 2);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    deque<int> q[3];
    rep(i, 1, n + 1) q[i % 3].push_back(i);
    map<int, int> ans;
    //0:red 1:blue
    if (red <= n / 3)
    {
        rep(i, 1, n + 1)
        {
            if (color[i] == 0)
            {
                ans[i] = q[0].front();
                q[0].pop_front();
            }
            else
            {
                for (int j = 2; j >= 0; j--)
                {
                    if (!q[j].empty())
                    {
                        ans[i] = q[j].front();
                        q[i].pop_front();
                    }
                }
            }
        }
    }
    else if (blue <= n / 3)
    {
        rep(i, 1, n + 1)
        {
            if (color[i] == 1)
            {
                ans[i] = q[0].front();
                q[0].pop_front();
            }
            else
            {
                for (int j = 2; j >= 0; j--)
                {
                    if (!q[j].empty())
                    {
                        ans[i] = q[j].front();
                        q[i].pop_front();
                    }
                }
            }
        }
    }
    else
    {
        rep(i, 1, n + 1)
        {
            if (color[i] == 0)
            {
                if (!q[1].empty())
                {
                    ans[i] = q[1].front();
                    q[1].pop_front();
                }
                else
                {
                    ans[i] = q[0].front();
                    q[0].pop_front();
                }
            }
            else
            {
                if (!q[2].empty())
                {
                    ans[i] = q[2].front();
                    q[2].pop_front();
                }
                else
                {
                    ans[i] = q[0].front();
                    q[0].pop_front();
                }
            }
        }
    }
    rep(i, 1, n + 1)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}