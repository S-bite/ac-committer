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
#define MOD 1000000007ll
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n, k;
    cin >> m >> n >> k;
    int x[m];
    rep(i, m) x[i] = 0;
    rep(i, n)
    {
        int t;
        cin >> t;
        x[t - 1]++;
    }
    int y[m];
    rep(i, m) y[i] = x[i];
    rep(i, m)
    {
        if (x[i] == 0)
            continue;
        rep(j, 1, k + 1)
        {
            if (i + j >= m)
                break;
            y[i + j]++;
        }

        rep(j, 1, k + 1)
        {
            if (i - j < 0)
                break;
            //cerr << i << "," << j << "," << i - 2 * j << endl;
            if ((i - 2 * j >= 0) && x[i - 2 * j] == 0)
            {
                y[i - j]++;
            }
        }
    }
    int ans = -1;
    rep(i, m)
    {
        ans = max(ans, y[i]);
    }
    cout << ans << endl;
    return 0;
}

//0 1 2 3 4 1 1 1