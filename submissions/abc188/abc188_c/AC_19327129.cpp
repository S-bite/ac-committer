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
    int n;
    cin >> n;
    ll m = 1 << n;
    vector<ll> per(m);
    map<ll, int> mp;
    vector<int> ans(m);

    rep(i, m)
    {
        cin >> per[i];
        mp[per[i]] = i;
    }
    int cur = 0;
    while (per.size() > 1)
    {
        vector<ll> next;
        rep(j, (int)per.size() / 2)
        {
            int i = 2 * j;
            if (per[i] > per[i + 1])
            {
                ans[cur] = mp[per[i + 1]];
                next.push_back(per[i]);
            }
            else
            {
                ans[cur] = mp[per[i]];
                next.push_back(per[i + 1]);
            }
            cur++;
        }
        per = next;
    }
    cout << ans[m - 2] + 1 << endl;
    return 0;
}