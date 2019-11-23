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
    int h, w, k;
    cin >> h >> w >> k;
    char g[h][w];
    rep(i, h) rep(j, w) cin >> g[i][j];
    int ans[h][w];
    rep(i, h) rep(j, w) ans[i][j] = -1;
    int cake = -1;

    rep(i, h)
    {
        bool first = true;
        rep(j, w)
        {
            if (g[i][j] == '#')
            {
                cake++;
                if (first)
                {
                    first = false;
                    for (int k = j; k >= 0; k--)
                    {
                        ans[i][k] = cake;
                    }
                }
                ans[i][j] = cake;
            }
            else
            {
                if (first == false)
                    ans[i][j] = cake;
            }
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if (ans[i][j] != -1)
            {
                continue;
            }
            int k = i;
            while (k >= 0)
            {
                if (ans[k][j] != -1)
                {
                    ans[i][j] = ans[k][j];
                    break;
                }
                k--;
            }
            k = i;
            if (ans[i][j] == -1)
            {
                while (k < h)
                {
                    if (ans[k][j] != -1)
                    {
                        ans[i][j] = ans[k][j];
                        break;
                    }
                    k++;
                }
            }
            assert(ans[i][j] != -1);
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            cout << ans[i][j] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
