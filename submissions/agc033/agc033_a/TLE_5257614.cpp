#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;
    vector<pair<int, int>> v;
    int g[h][w];
    rep(i, h)
    {
        string s;
        cin >> s;
        rep(j, w)
        {
            if (s[j] == '#')
            {
                v.push_back({i, j});
            }
            g[i][j] = (s[j] == '#' ? 1 : 0);
        }
    }
    ll ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if (g[i][j] == 0)
            {
                ll dist = 10000;

                rep(k, v.size())
                {
                    dist = min(dist, abs(v[k].first - i) + abs(v[k].second - j));
                }
             //   cerr << i << "," << j << "," << dist << endl;
                ans = max(ans, dist);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
