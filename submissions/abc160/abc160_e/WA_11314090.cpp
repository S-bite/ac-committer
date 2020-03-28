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
    int x_ = x;
    int y_ = y;

    vector<ll> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];
    sort(ALL(p), greater<ll>());
    sort(ALL(q), greater<ll>());
    p.push_back(-1);
    q.push_back(-1);
    int curp = 0, curq = 0;
    map<int, bool> used;
    rep(i, c) used[i] = false;
    priority_queue<pair<ll, int>> red;
    rep(i, a) red.push({p[i], c + 1});
    rep(i, c) red.push({r[i], i});
    priority_queue<pair<ll, int>> blue;
    rep(i, b) blue.push({q[i], c + 1});
    rep(i, c) blue.push({r[i], i});
    ll ans1 = 0;
    //1
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
            ans1 += blue.top().first;
            if (blue.top().second != c + 1)
            {
                used[blue.top().second] = true;
            }
            else
            {
                curq++;
            }
            blue.pop();
            y--;
        }
        else if (y == 0)
        {
            assert(!red.empty());
            ans1 += red.top().first;
            if (red.top().second != c + 1)
            {
                used[red.top().second] = true;
            }
            else
            {
                curp++;
            }
            red.pop();
            x--;
        }
        else
        {
            if (q[curq] < p[curp])
            {
                assert(!blue.empty());
                ans1 += blue.top().first;
                if (blue.top().second != c + 1)
                {
                    used[blue.top().second] = true;
                }
                else
                {
                    curq++;
                }

                blue.pop();
                y--;
            }
            else
            {
                assert(!red.empty());
                ans1 += red.top().first;
                if (red.top().second != c + 1)
                {
                    used[red.top().second] = true;
                }
                else
                {
                    curp++;
                }

                red.pop();
                x--;
            }
        }
    }

    cout << ans1 << endl;
    return 0;
}
