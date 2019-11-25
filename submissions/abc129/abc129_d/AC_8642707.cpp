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
int main(int argc, char const *argv[])
{

    int h, w;
    cin >> h >> w;
    string wall = "";
    rep(i, w) wall += "#";
    vector<string> g(h + 2, "");
    g[0] = wall;
    g[h + 1] = wall;
    vector<vector<int>> lastw(h + 2);
    vector<vector<int>> lasth(w + 2);
    rep(i, h) cin >> g[i + 1];
    rep(j, w) lasth[j].push_back(h);

    rep(i, h + 2)
    {
        g[i] = "#" + g[i] + "#";
    }
    rep(i, h + 2)
    {
        rep(j, w + 2)
        {
            if (g[i][j] == '#')
            {
                lasth[j].push_back(i);
                lastw[i].push_back(j);
            }
        }
    }
    rep(i, h + 2)
    {
        cerr << g[i] << endl;
    }
    int ans = -1;
    rep(i, 1, h + 1)
    {
        rep(j, 1, w + 1)
        {
            if (g[i][j] == '#')
                continue;
            int hsize = (*lower_bound(ALL(lasth[j]), i)) - (*(lower_bound(ALL(lasth[j]), i) - 1));
            int wsize = (*lower_bound(ALL(lastw[i]), j)) - (*(lower_bound(ALL(lastw[i]), j) - 1));
            //cerr << i << " " << j << " " << hsize << " " << wsize << endl;
            ans = max(ans, hsize + wsize - 3);
        }
    }
    cout << ans << endl;
    return 0;
}
