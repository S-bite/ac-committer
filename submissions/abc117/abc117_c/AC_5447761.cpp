#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int x[m];
    rep(i, m) cin >> x[i];
    if (n >= m)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(x, x + m);
    int l[m - 1];
    rep(i, m - 1) l[i] = x[i + 1] - x[i];
    sort(l, l + m - 1, greater<int>());
    int ans = x[m - 1] - x[0];
    rep(i, n - 1)
    {
        cerr << ans << endl;
        ans -= l[i];
    }
    cout << ans << endl;
    return 0;
}
