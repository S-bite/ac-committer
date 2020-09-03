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

int nearest_pos(VL &v, int n, ll x)
{
    int lo = 0, hi = n;
    while (lo + 1 != hi)
    {
        int mid = (lo + hi) / 2;
        if (x <= v[mid])
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    if (lo == n - 1)
        return lo;
    if (llabs(x - v[lo]) <= llabs(x - v[lo + 1]))
    {
        return lo;
    }
    else
    {
        return lo + 1;
    }
}

void solve(VL &v, int n, ll x, VL &sum, VL &esum)
{
    int start = nearest_pos(v, n, x);

    if (start == n - 1 || start == n - 2)
    {
        if (n % 2 == 1)
        {
            cout << esum[n] << "\n";
        }
        else
        {
            cout << sum[n] - esum[n] << "\n";
        }
        return;
    }
    int hi = n - start, lo = (hi + 1) / 2;
    while (lo + 1 != hi)
    {
        int mid = (hi + lo) / 2;
        int left = n - 1 - 2 * mid;
        if (left < 0)
        {
            hi = mid;
            continue;
        }
        if (llabs(x - v[left]) <= llabs(n - mid + 1))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    int left = n - 1 - 2 * lo;
    //cerr << "left " << left << endl;
    ll more = 0;
    if (left >= 0)
    {
        more = (n % 2 == 1 ? esum[left + 1] : sum[left + 1] - esum[left]);
    }
    //cerr << "lo " << lo << endl;
    //cerr << "more " << more << endl;
    cout << sum[n] - sum[n - lo] + more << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    VL v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    // cerr << "start " << start << endl;
    VL sum(n + 1, 0);
    rep(i, n) sum[i + 1] = sum[i] + v[i];
    VL esum(n + 1, 0);
    rep(i, n)
    {
        esum[i + 1] = esum[i];
        if (i % 2 == 0)
        {
            esum[i + 1] += v[i];
        }
    }
    rep(i, q)
    {
        ll x;
        cin >> x;
        solve(v, n, x, sum, esum);
    }
    return 0;
}