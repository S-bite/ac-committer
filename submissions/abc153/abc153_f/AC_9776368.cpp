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
    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<ll, ll>> m(n);
    rep(i, n) cin >> m[i].first >> m[i].second;
    ll ans = 0;
    ll cura = 0;
    sort(ALL(m));
    deque<pair<int, int>> que;
    rep(i, n)
    {
        ll curx = m[i].first;
        ll curh = m[i].second;
        while (!que.empty() && que.front().first < curx)
        {
            cura -= que.front().second;
            que.pop_front();
        }

        curh -= cura * a;
        if (curh <= 0)
        {
            continue;
        }
        ll need = (curh + a - 1) / a;
        cura += need;
        ans += need;
        que.push_back({curx + 2 * d, need});
    }
    cout << ans << endl;
    return 0;
}
