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
    VL v(n);
    priority_queue<pair<ll, int>> pque;
    rep(i, n)
    {
        cin >> v[i];
        pque.push({ v[i], -(i + 1) });
    }
    ll num = 0;
    ll sum = 0;
    VL ans(n + 1, 0);
    while (!pque.empty()) {
        int idx = -pque.top().second;
        ll val = pque.top().first;
        // cerr << idx << " " << val << endl;
        pque.pop();
        num++;
        sum += val;
        while (!pque.empty()) {
            if (idx < -pque.top().second) {
                sum += pque.top().first;
                num++;
                pque.pop();
            } else {
                break;
            }
        }
        if (pque.empty()) {
            ans[idx] += sum;
            break;
        }
        ans[idx] += (sum - pque.top().first * num);
        sum = pque.top().first * num;
    }
    rep(i, 1, n + 1)
    {
        cout << ans[i] << endl;
    }

    return 0;
}