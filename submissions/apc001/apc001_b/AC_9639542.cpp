#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    ll mi = 0, pl = 0;
    ll diff = 0;
    rep(i, n)
    {
        c[i] = a[i] - b[i];
    }
    rep(i, n)
    {
        if (c[i] > 0)
        {
            pl += c[i];
        }
        else
        {
            mi -= c[i] / 2;
        }
        cerr << c[i] << " ";
    }
    cerr << endl;
    cerr << pl << " " << mi << " " << diff << endl;
    if (pl <= mi)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
