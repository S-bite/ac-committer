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
    vector<vector<int>> g(h, vector<int>(w, 0));
    rep(i, h) rep(j, w) cin >> g[i][j];
    int st = -1;
    int best = 0;

    rep(i, h)
    {
        int now = 0;
        rep(j, w)
        {
            now += g[i][j];
        }
        if (now > best)
        {
            best = now;
            st = i;
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if (i == st)
                cout << "#";
            else
                cout << (j % 2 == 0 ? "#" : ".");
        }
        cout << endl;
    }
    return 0;
}
