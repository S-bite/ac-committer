#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmin(x, y) x = min(x, y);
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    if (m > n)
    {
        cout << "no" << endl;
        return 0;
    }
    int cur = 0;
    rep(i, m)
    {
        bool ok = false;
        rep(j, cur, n)
        {
            if (a[j] > b[i])
            {
                cout << "no" << endl;
                return 0;
            }
            if (b[i] - a[j] <= t)
            {
                ok = true;
                cur = j + 1;
                break;
            }
        }
        if (ok == false)
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}
