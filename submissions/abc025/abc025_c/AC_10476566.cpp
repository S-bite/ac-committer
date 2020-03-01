#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

int eval(VVI &b, VVI &c, VVI &g)
{
    /*rep(i, 3)
    {
        rep(j, 3) cerr << g[i][j];
        cerr << endl;
    }*/
    int ret = 0;
    rep(i, 2)
    {
        rep(j, 3)
        {
            if (g[i][j] == g[i + 1][j])
            {
                ret += b[i][j];
            }
        }
    }
    rep(i, 3)
    {
        rep(j, 2)
        {
            if (g[i][j] == g[i][j + 1])
            {
                ret += c[i][j];
            }
        }
    }
    return ret;
}

int miniMax(VVI &b, VVI &c, VVI &cur, int turn)
{

    int ret;
    int mark = turn % 2;
    if (turn == 9)
    {
        return eval(b, c, cur);
    }
    if (mark == 0) //maximize
    {
        ret = -1;
        rep(i, 3) rep(j, 3)
        {
            if (cur[i][j] == -1)
            {
                cur[i][j] = mark;
                ret = max(ret, miniMax(b, c, cur, turn + 1));
                cur[i][j] = -1;
            }
        }
    }
    else //minimize
    {
        ret = IINF;
        rep(i, 3) rep(j, 3)
        {
            if (cur[i][j] == -1)
            {
                cur[i][j] = mark;
                ret = min(ret, miniMax(b, c, cur, turn + 1));
                cur[i][j] = -1;
            }
        }
    }
    return ret;
}

int main()
{
    VVI b(2, VI(3));
    VVI c(3, VI(2));
    VVI g(3, VI(3, -1));
    int sum = 0;
    rep(i, 2) rep(j, 3)
    {
        cin >> b[i][j];
        sum += b[i][j];
    }
    rep(i, 3) rep(j, 2)
    {
        cin >> c[i][j];
        sum += c[i][j];
    }
    int ans = miniMax(b, c, g, 0);
    cout << ans << endl
         << sum - ans << endl;
    return 0;
}