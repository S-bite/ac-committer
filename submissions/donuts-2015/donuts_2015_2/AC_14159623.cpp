#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
int n, m;
VVI combo;
VI bonus;
VI v;

int ans = -1;

void calc(map<int, bool> &mp)
{
    int cost = 0;

    rep(i, n)
    {
        if (mp[i])
        {
            //cerr << i << " ";
            cost += v[i];
        }
    }
    //cerr << endl;
    rep(i, m)
    {
        int num = 0;
        for (auto &&x : combo[i])
        {
            if (mp[x])
                num++;
        }
        if (num >= 3)
        {
            cost += bonus[i];
        }
    }
    //cerr << cost << endl;
    chmax(ans, cost);
}

void dfs(int cur, int last, map<int, bool> &mp)
{
    if (cur == 9)
    {
        calc(mp);
    }
    rep(i, last + 1, n)
    {
        mp[i] = true;
        dfs(cur + 1, i, mp);
        mp[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    combo = VVI(m);
    bonus = VI(m);
    v = VI(n);
    rep(i, n) cin >> v[i];
    rep(i, m)
    {
        int t;
        cin >> bonus[i];
        cin >> t;

        rep(j, t)
        {
            int tt;
            cin >> tt;
            tt--;
            combo[i].push_back(tt);
        }
    }
    map<int, bool> mp;
    dfs(0, -1, mp);
    cout << ans << endl;

    return 0;
}
