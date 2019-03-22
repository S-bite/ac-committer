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
    map<int, vector<pair<int, ll>>> mp;
    rep(i, n - 1)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        mp[a].push_back(make_pair(b, c));
        mp[b].push_back(make_pair(a, c));
    }
    int q, k;
    cin >> q >> k;

    ll cost[n + 1];
    map<int, bool> unuse;

    rep(i, n + 1)
    {

        cost[i] = INF;
        unuse[i] = true;
    }
    cost[k] = 0;

    unuse.erase(0);
    queue<int> qu;
    qu.push(k);
    unuse[k] = false;

    while (!qu.empty())
    {
        int t = qu.front();
        qu.pop();
        for (auto k : mp[t])
        {
            if (unuse[k.first])
            {
                unuse[k.first] = false;
                cerr << t << "," << k.first << "." << k.second << endl;
                qu.push(k.first);
                cost[k.first] = cost[t] + k.second;
            }
        }
    }
    rep(i, n)
    {
        cerr << i << ":" << cost[i] << endl;
    }

    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        cout << cost[x] + cost[y] << endl;
    }

    return 0;
}
