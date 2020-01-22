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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    if (n > m)
    {
        cout << "Y" << endl;
        return 0;
    }
    if (n < m)
    {
        cout << "X" << endl;
        return 0;
    }
    rep(i, n)
    {
        if (a[i] < b[i])
        {
            cout << "X" << endl;
            return 0;
        }
        if (a[i] > b[i])
        {
            cout << "Y" << endl;
            return 0;
        }
    }
    cout << "Same" << endl;
    return 0;
}
