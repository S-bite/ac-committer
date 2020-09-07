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
const ll INF = 1ll << 50;
const ll MOD = 1000000007;

ll solve_naive(VL v, int n, ll x)
{
    ll ans = 0;
    bool flag = true;
    while (flag == true)
    {

        flag = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] != -1)
            {
                ans += v[i];
                v[i] = -1;
                flag = true;
                break;
            }
        }
        ll near = INF;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == -1)
            {
                continue;
            }
            if (llabs(x - v[i]) < llabs(x - near))
            {
                idx = i;
                flag = true;
                near = v[i];
            }
        }
        if (idx != -1)
        {
            v[idx] = -1;
        }
    }
    return ans;
}

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
    //cerr << "start " << start << endl;
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
    //逆順のindex
    int hi = n - start - 1, lo = hi / 2;
    //cerr << hi << " " << lo << endl;

    while (lo + 1 != hi)
    {
        int mid = (hi + lo) / 2;

        int left = n - 2 * (mid + 1);
        //   cerr << hi << " " << lo << " " << mid << " " << left << endl;
        if (n % 2 == 1 && left == -1)
            left = 0;

        if (left < 0)
        {
            hi = mid;
            continue;
        }
        if (left == 0)
        {
            lo = mid;
            continue;
        }
        //cerr << llabs(x - v[left - 1]) << " " << llabs(x - v[n - mid - 1]) << endl;
        if (llabs(x - v[left - 1]) <= llabs(x - v[n - mid - 1]))
        {
            // cerr << "lo" << endl;
            lo = mid;
        }
        else
        {
            // cerr << "hi" << endl;
            hi = mid;
        }
    }

    int left = n - 2 * (lo + 1);
    // cerr << "left " << left << endl;
    ll more = 0;
    if (left >= 1)
    {
        more = (n % 2 == 1 ? esum[left + 1] : sum[left + 1] - esum[left]);
    }
    //cerr << "lo " << lo << endl;
    // cerr << "more " << more << endl;
    cout << sum[n] - sum[n - lo - 1] + more << "\n";
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
    sort(ALL(v));
    //cerr << "start " << start << endl;
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
        cerr << "naive " << solve_naive(v, n, x) << endl;
        solve(v, n, x, sum, esum);
    }
    return 0;
}