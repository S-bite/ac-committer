#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int w, h, n;
    cin >> w >> h >> n;
    int board[h][w];
    rep(i, h) rep(j, w) board[i][j] = 0;
    rep(i, n)
    {
        int x, y, a;
        cin >> x >> y >> a;
        rep(ii, h) rep(jj, w)
        {
            if (a == 1 && jj < x)
            {
                board[ii][jj] = 1;
            }
            else if (a == 2 && jj >= x)
            {
                board[ii][jj] = 1;
            }
            else if (a == 3 && ii < y)
            {
                board[ii][jj] = 1;
            }
            else if (a == 4 && ii >= y)
            {
                board[ii][jj] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if (board[i][j] == 0)
            {
                ans++;
            }
            cerr << board[i][j];
        }
        cerr << endl;
    }
    cout << ans << endl;
    return 0;
}
