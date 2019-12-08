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
int n;

int ok(vector<vector<int>> &v, int m)

{
    int d[n];
    int ret = 0;
    rep(i, n)
    {
        d[i] = (m >> i) & 1;
        if (d[i] == 1)
            ret++;
    }
    rep(i, n)
    {
        rep(j, n)
        {
            if (v[i][j] == -1)
                continue;
            if (d[i] == 1 && d[j] != v[i][j])
            {
                return 0;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, -1));
    rep(i, n)
    {
        int m;
        cin >> m;
        rep(j, m)
        {
            int x, y;
            cin >> x >> y;
            x--;
            v[i][x] = y;
        }
    }
    cerr << "ok" << pow(2, n) << endl;
    int ans = 0;
    rep(i, pow(2, n))
    {
        cerr << "*" << i << endl;
        ans = max(ans, ok(v, i));
    }
    cout << ans << endl;
    return 0;
}
