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
map<int, vector<int>> g;
map<int, ll> cnt;
map<int, ll> ans;
map<int, bool> visit;

void bfs(int now, ll cost)
{
    visit[now] = true;
    //cerr << now << "," << cnt[now] << endl;
    ans[now] = cost + cnt[now];
    for (auto x : g[now])
    {
        if (visit[x] == false)
        {
            bfs(x, cost + cnt[now]);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n >> q;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, q)
    {
        int p, x;
        cin >> p >> x;
        //cerr << "p " << p << " x " << x << endl;
        cnt[p] += x;
    }
    bfs(1, 0);
    rep(i, 1, n + 1)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
