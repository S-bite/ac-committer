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

void make(vector<int> &v, map<int, vector<int>> &g, int now, vector<int> &attr, int depth)
{
    if (depth == 2)
    {
        for (auto x : g[now])
        {
            attr[now] = min(3, attr[now]);
            v.push_back(x);
        }
        return;
    }
    for (auto x : g[now])
    {
        if (attr[x] <= depth)
            continue;
        attr[x] = depth;
        make(v, g, x, attr, depth + 1);
    }
    return;
}

//attrは10で初期化！
int main()
{
    int n;
    cin >> n;
    ll m;
    cin >> m;
    map<int, vector<int>> g1, g2;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g1[a].push_back(b);
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    map<int, bool> visited;
    deque<int> que;

    rep(i, n)
    {
        vector<int> v2;
        vector<int> attr(n, 10);
        make(v2, g1, i, attr, 0);
        g2[i] = v2;
    }

    visited.clear();
    que.clear();
    que.push_back(s);
    int ans = 0;
    map<deque<int>, bool> state;
    while (true)
    {
        deque<int> next;

        next.clear();
        while (!que.empty())
        {
            int now = que.back();
            que.pop_back();
            for (auto x : g2[now])
            {
                //       cerr << x << " ";
                next.push_back(x);
                visited[x] = true;
            }
        }
        //cerr << endl;
        que = next;

        ans++;
        //cerr << que.back() << endl;
        if (visited[t] == true)
        {
            cout << ans << endl;
            return 0;
        }
        else if (state[que] == true)
        {
            cout << -1 << endl;
            return 0;
        }
        state[que] = true;
    }
}
