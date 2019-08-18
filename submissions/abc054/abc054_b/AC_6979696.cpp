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

int n, m;

bool check(vector<string> &a, vector<string> &b, int y, int x)
{
    rep(i, m) rep(j, m)
    {
        if (b[i][j] != a[i + y][j + x])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    vector<string> a(n, "");
    vector<string> b(m, "");
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    rep(x, n - m + 1) rep(y, n - m + 1)
    {
        if (check(a, b, y, x))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
