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

vector<vector<int>> group(101010);
vector<int> id(101010);

void unite(int a, int b)
{
    int ga = id[a];
    int gb = id[b];
    if (ga == gb)
        return;
    if (group[ga].size() < group[gb].size())
    {
        swap(ga, gb);
    }
    for (auto x : group[gb])
    {
        group[ga].push_back(x);
        id[x] = ga;
    }
    group[gb].clear();
}

bool same_root(int a, int b)
{
    //cerr << a << ":" << id[a] << endl;
    //cerr << b << ":" << id[b] << endl;
    return id[a] == id[b];
}

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, n)
    {
        group[i] = {i};
        id[i] = i;
    }
    VI p(n);
    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
    }
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        unite(x, y);
    }
    ll ans = 0;
    rep(i, n)
    {
        if (group[i].empty())
            continue;
        map<int, bool> mp;
        for (auto &&x : group[i])
        {
            mp[x] = true;
        }
        for (auto &&x : group[i])
        {
            if (mp[p[x]])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}