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

int main()
{
    int n;
    cin >> n;
    ll m;
    cin >> m;
    map<int, vector<int>> g;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;

    map<int, bool> visited;
    vector<int> mark(n, -1); //2:実際に訪れることができる 0:飛び超える(1) 1:飛び越える(2)
    map<int, int> cost;
    deque<int> que;

    //visited[s] = true;
    cost[s] = 0;
    mark[s] = 2;
    que.push_back(s);
    int ans = 0;
    while (true)
    {
        deque<int> next;

        rep(i, 3)
        {
            next.clear();
            while (!que.empty())
            {
                int now = que.back();
                que.pop_back();
                for (auto x : g[now])
                {
                    if (visited[x] == true)
                    {

                        //                 continue;
                    }
                    next.push_back(x);
                    //  cerr << x + 1 << " ";
                    if (i == 2)
                        visited[x] = true;
                }
            }
            //   cerr << endl;

            que = next;
        }
        ans++;
        // cerr << que.size() << endl;
        if (visited[t] == true)
        {
            cout << ans << endl;
            return 0;
        }
        else if (que.size() == 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
}
