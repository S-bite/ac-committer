#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main(int argc, char const *argv[])
{
    int h, w, d;
    cin >> h >> w >> d;
    map<int, pair<int, int>> mp;
    rep(i, h) rep(j, w)
    {
        int a;
        cin >> a;
        mp[a] = make_pair(i + 1, j + 1);
        dump(i);
        dumpl(j);
    }
    ll cost[h * w + 1];
    rep(i, h * w + 1) cost[i] = 0;
    rep(i, 1, d + 1)
    {
        int now = i;
        now += d;
        while (now < h * w)
        {
            cost[now] = cost[now - d] + abs(mp[now].first - mp[now - d].first) + abs(mp[now].second - mp[now - d].second);
            now += d;
        }
    }

    int q;
    cin >> q;
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        cout << cost[r] - cost[l] << endl;
    }
    return 0;
}
