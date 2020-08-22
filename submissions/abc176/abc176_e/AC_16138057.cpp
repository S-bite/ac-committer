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

int main()
{
    int h, w, m;
    cin >> h >> w >> m;
    map<int, int> hnum, wnum;
    map<PII, bool> mp;
    rep(i, m)
    {
        int y, x;
        cin >> y >> x;
        y--;
        x--;
        hnum[y]++;
        wnum[x]++;
        mp[{y, x}] = true;
    }
    priority_queue<PII> pque_x, pque_y;
    rep(i, w)
    {
        pque_x.push({wnum[i], i});
    }
    rep(i, h)
    {
        pque_y.push({hnum[i], i});
    }
    int ans = pque_x.top().first + pque_y.top().first - 1;

    VI candid_x;
    int tmp = pque_x.top().first;
    while (pque_x.empty() == false && pque_x.top().first == tmp)
    {
        candid_x.push_back(pque_x.top().second);
        pque_x.pop();
    }

    VI candid_y;
    tmp = pque_y.top().first;
    while (pque_y.empty() == false && pque_y.top().first == tmp)
    {
        candid_y.push_back(pque_y.top().second);
        pque_y.pop();
    }

        for (auto &&y : candid_y)
    {
        for (auto &&x : candid_x)
        {
            if (mp[{y, x}] == false)
            {
                cout << ans + 1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}