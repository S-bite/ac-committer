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

//attrは10で初期化！
int main()
{
    int n;
    cin >> n;
    ll m;
    cin >> m;
    if (m == 0)
    {
        cout << -1 << endl;
        return 0;
    }
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
    map<pair<int, int>, bool> visited;
    deque<int> que;
    vector<int> attr(n, 10);
    vector<int> v2;

    que.push_back(s);
    int ans = 0;
    map<pair<deque<int>, int>, bool> state;
    while (true)
    {
        deque<int> next;

        next.clear();
        while (!que.empty())
        {
            int now = que.back();
            que.pop_back();
            for (auto x : g1[now])
            {
                if (visited[{x, ans % 3}] == true)
                    continue;
                //cerr << x << " ";
                next.push_back(x);
                visited[{x, ans % 3}] = true;
            }
        }
        //cerr << endl;
        que = next;

        ans++;
        if (visited[{t, (ans - 1) % 3}] == true && ans % 3 == 0)
        {
            cout << ans / 3 << endl;
            return 0;
        }
        else if (state[{que, ans % 3}] == true)
        {
            cout << -1 << endl;
            return 0;
        }
        visited[{t, (ans - 1) % 3}] = false;
        state[{que, ans % 3}] = true;
    }
}
