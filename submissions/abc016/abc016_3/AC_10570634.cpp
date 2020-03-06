#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmin(x, y) x = min(x, y);
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> g;
    map<int, bool> pushed, visited;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    map<int, bool> frend, used;
    int ans;
    rep(i, n)
    {
        ans = 0;
        frend.clear();
        used.clear();
        frend[i] = true;

        for (auto x : g[i])
        {
            frend[x] = true;
        }
        for (auto x : g[i])
        {
            for (auto y : g[x])
            {
                if (frend[y] == false && used[y] == false)
                {
                    ans++;
                    used[y] = true;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
