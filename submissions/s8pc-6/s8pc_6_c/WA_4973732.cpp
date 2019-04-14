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
int h, w;

void search(vector<vector<char>> &g, vector<vector<bool>> &b, int y, int x)
{
   // cerr << y << "," << x << endl;
    if (b[y][x] == true)
        return;
    b[y][x] = true;
    if (y + 1 < h && g[y + 1][x] == '.')
    {
        search(g, b, y + 1, x);
    }
    if (x + 1 < w && g[y][x + 1] == '.')
    {
        search(g, b, y, x + 1);
    }
    return;
}

int main()
{
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w, '-'));
    vector<vector<bool>> b(h, vector<bool>(w, false));

    rep(i, h) rep(j, w) cin >> g[i][j];
    search(g, b, 0, 0);

    int ind = -1;
    rep(i, h)
    {
        ind = i;
        rep(j, w)
        {
            if (g[i][j] == '#')
            {
                ind = -1;
                break;
            }
        }
        if (ind == i)
            break;
    }
    if (ind == -1)
    {
        cout << ":(" << endl;
        return 0;
    }
    if (b[ind][0] == true)
        cout << "Yay!" << endl;
    else
        cout << ":(" << endl;
    return 0;
}