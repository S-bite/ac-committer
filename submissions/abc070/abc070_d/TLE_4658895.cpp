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
#define INF (1ll << 60)
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<pair<int, int>, ll> mp;
    rep(i, n - 1)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        mp[make_pair(a, b)] = c;
    }
    ll cost[n + 1];
    rep(i, n + 1) cost[i] = INF;
    int q, k;
    cin >> q >> k;
    cost[k] = 0;
    while (!mp.empty())
    {

        auto old = mp;
        for (auto k : old)
        {
            int a = k.first.first, b = k.first.second;
            ll c = k.second;
            if (cost[a] != INF || cost[b] != INF)
            {
                cost[a] = min(cost[a], cost[b] + c);
                cost[b] = min(cost[b], cost[a] + c);
                mp.erase(k.first);
            }
        }
    }
    dumpl(q);
    dumpl(k);
    dumpl(n);
    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        cout << cost[x] + cost[y] << endl;
    }

    return 0;
}
