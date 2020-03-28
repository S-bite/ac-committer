#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];
    map<int, bool> used;
    rep(i, c) used[i] = false;
    priority_queue<pair<ll, int>> red;
    rep(i, a) red.push({p[i], -1});
    rep(i, c) red.push({r[i], i});
    priority_queue<pair<ll, int>> blue;
    rep(i, b) blue.push({q[i], -1});
    rep(i, c) blue.push({r[i], i});
    ll ans = 0;
    while (x > 0 || y > 0)
    {
        while (used[red.top().second] && !red.empty())
        {
            red.pop();
        }
        while (used[blue.top().second] && !blue.empty())
        {
            blue.pop();
        }
        if (x == 0)
        {
            assert(!blue.empty());
            ans += blue.top().first;
            if (blue.top().second != -1)
            {
                used[blue.top().second] = true;
            }
            blue.pop();
            y--;
        }
        else if (y == 0)
        {
            assert(!red.empty());
            ans += red.top().first;
            if (red.top().second != -1)
            {
                used[red.top().second] = true;
            }
            red.pop();
            x--;
        }
        else
        {
            if (red.top().first < blue.top().first)
            {
                assert(!blue.empty());

                ans += blue.top().first;
                if (blue.top().second != -1)
                {
                    used[blue.top().second] = true;
                }
                blue.pop();
                y--;
            }
            else
            {
                assert(!red.empty());

                ans += red.top().first;
                if (red.top().second != -1)
                {
                    used[red.top().second] = true;
                }
                red.pop();
                x--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}