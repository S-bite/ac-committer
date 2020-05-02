#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int n, m;
int dist(int x, int y)
{
    return min(abs(x - y), n - abs(x - y));
}
int main()
{
    cin >> n >> m;
    VI tmp(n);
    rep(i, n)
    {
        if (i % 2 == 0)
        {
            tmp[i] = i / 2 + 1;
        }
        else
        {
            tmp[i] = n - i / 2;
        }
    }
    vector<PII> ans;

    map<int, int> used;
    int pad = 0; // (n % 2 == 0 && m % 2 == 1) ? 1 : 0;
    rep(i, m)
    {
        int x = tmp[2 * i];
        int y = tmp[2 * (i + pad) + 1];

        if (used[dist(x, y)] || used[n - dist(x, y)])
        {
            pad = 1;
        }
        x = tmp[2 * i];
        y = tmp[2 * (i + pad) + 1];
        assert(2 * (i + pad) + 1 < n);
        ans.push_back({x, y});
        used[dist(x, y)] = true;
        used[n - dist(x, y)] = true;
    }
    used.clear();
    map<int, bool> mm;
    for (auto &&x : ans)
    {
        cout << x.first << " " << x.second << endl;
        assert(x.first <= n && x.second <= n);
        assert(x.first != x.second);
        cerr << dist(x.first, x.second) << endl;
        assert(used[dist(x.first, x.second)] == false && used[n - dist(x.first, x.second)] == false);
        used[dist(x.first, x.second)] = true;
        used[n - dist(x.first, x.second)] = true;
        assert(mm[x.first] == false && mm[x.second] == false);
        mm[x.first] = true;
        mm[x.second] = true;
    }
    return 0;
}
