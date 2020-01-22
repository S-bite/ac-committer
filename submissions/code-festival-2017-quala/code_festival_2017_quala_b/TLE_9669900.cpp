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
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> v(n * m + 1, false);
    rep(i, n + 1) rep(j, m + 1)
    {
        v[(i * m + j * n - 2 * (i * j))] = true;
        cerr << i << " " << j << " " << (i * m + j * n - (i * j)) << endl;
    }
    if (v[k] == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
