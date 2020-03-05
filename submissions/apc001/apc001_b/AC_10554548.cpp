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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> c(n);
    rep(i, n) c[i] = a[i] - b[i];
    ll cansub = 0;
    ll mustsub = 0;
    rep(i, n)
    {
        if (c[i] > 0)
        {
            mustsub += c[i];
        }
        else
        {
            cansub -= c[i] / 2;
        }
    }
    cerr << cansub << " " << mustsub << endl;
    if (cansub >= mustsub)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
