#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    ll x, y;
    cin >> x >> y;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    a.push_back(INF);
    b.push_back(INF);
    int acur = 0, bcur = 0;
    int time = 0;
    int ans = 0;
    bool goa = false;
    while (true)
    {
        cerr << time << endl;
        if (goa)
        {
            while (time > b[bcur])
                bcur++;
            if (b[bcur] == INF)
                break;
            time = b[bcur] + y;
            ans++;
        }
        else
        {
            while (time > a[acur])
                acur++;
            if (a[acur] == INF)
                break;
            time = a[acur] + x;
            ans++;
        }
        goa ^= 1;
    }
    cout << ans / 2 << endl;
    return 0;
}