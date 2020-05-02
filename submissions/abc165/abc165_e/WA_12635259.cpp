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

int main()
{
    int n, m;
    cin >> n >> m;
    VI tmp(n);
    rep(i, n)
    {
        if (i % 2 == 0)
        {
            tmp[i] = i + 1;
        }
        else
        {
            tmp[i] = n - i;
        }
    }

    int cur = 1;
    vector<PII> ans;

    map<int, int> used;
    int pad = 0;
    rep(i, m)
    {
        if (used[abs(tmp[2 * i + pad] - tmp[2 * i + 1 + pad])])
        {
            if (pad == 1)
            {
                assert(false);
            }
            pad = 1;
        }
        // if (i % 2 == 0)
        ans.push_back({tmp[2 * i + pad], tmp[2 * i + 1 + pad]});
        used[abs(tmp[2 * i + pad] - tmp[2 * i + 1 + pad])] = true;
        // else
        // {
        //     ans.push_back({tmp[n - 1 - 2 * i + 1 - n % 2], tmp[n - 2 - 2 * i + 1 - n % 2]});
        // }
    }
    used.clear();
    for (auto &&x : ans)
    {
        cout << x.first << " " << x.second << endl;
        assert(used[abs(x.first - x.second)] == false);
        used[abs(x.first - x.second)] = true;
    }
    return 0;
}