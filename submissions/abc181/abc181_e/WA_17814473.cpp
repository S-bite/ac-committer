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
const ll INF = 1ll << 58;
const ll MOD = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> v;
    vector<ll> child(n);
    rep(i, n)
    {
        ll t;
        cin >> t;
        child[i] = t;
        v.push_back({ t, 0 });
    }
    sort(ALL(child));
    ll backsumeven = 0;

    ll frontsum = 0;
    rep(i, n - 1)
    {
        if (i % 2 == 1) {
            backsumeven += child[i + 1] - child[i];
        } else {
        }
    }
    child.push_back(INF);
    rep(i, m)
    {
        ll t;
        cin >> t;
        v.push_back({ t, 1 });
    }

    sort(ALL(v));
    rep(i, v.size())
    {
    }
    cerr << endl;
    ll ans = INF;

    int next = 0;
    ll tmp = 0;
    rep(i, v.size())
    {
        //cerr << ans << " " << frontsum << " " << backsumodd << " " << backsumeven << endl;
        if (v[i].second == 1) {
            if (next % 2 == 0) {
                if (next < m) {
                    assert(backsumeven >= 0);
                    chmin(ans, frontsum + backsumeven + (child[next] - v[i].first));
                }
            } else {
                assert(backsumeven >= 0);
                //cerr << "low" << endl;
                chmin(ans, frontsum + backsumeven + (v[i].first - child[next - 1]));
            }
        } else {
            int cur = next;
            if (cur % 2 == 0) {
            } else {
                frontsum += child[cur] - child[cur - 1];
                backsumeven -= child[cur + 1] - child[cur];
            }

            next++;
        }
    }
    cout << ans << endl;
    return 0;
}