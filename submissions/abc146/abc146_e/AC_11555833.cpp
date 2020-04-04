#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (a); i < (b); ++i)
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
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    vector<ll> v(n);
    vector<ll> sum(n + 1, 0);

    rep(i, n)
    {
        cin >> v[i];

        v[i]--;
    }

    rep(i, n)
    {
        sum[i + 1] = sum[i] + v[i];
        cerr << sum[i + 1] << " ";
    }
    cerr << endl;
    ll ans = 0;
    rep(i, 1, n + 1)
    {
        if (i > k)
        {
            //cerr << "del " << i - k << endl;
            mp[sum[i - k] % k]--;
        }
        ll cur = sum[i] % k;
        if (cur == 0)
        {
            //cerr << i << " " << cur << " " << mp[0] << endl;
            ans += mp[0];
            if (i < k)
                ans++;
        }
        else
        {
            //cerr << i << " " << cur << " " << mp[cur] << endl;
            ans += mp[cur];
        }
        mp[cur]++;
    }
    cout << ans << endl;

    return 0;
}
