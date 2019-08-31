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
//最初は貪欲！！！！！
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int b[3];
    cin >> b[0] >> b[1] >> b[2];
    vector<vector<int>> l(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> l[i][j];

    vector<vector<int>> r(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> r[i][j];

    rep(i, n)
    {
        rep(j, n)
        {
            cout << (l[i][j] + r[i][j]) / 2 << " ";
        }
        cout << endl;
    }
    return 0;
}
