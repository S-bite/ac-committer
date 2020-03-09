#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;

int score(vector<int> &v, int s, int t, bool b)
{
    if (t < s)
        swap(s, t);
    bool myturn = b;
    int ret = 0;
    rep(i, s, t + 1)
    {
        if (myturn)
            ret += v[i];
        myturn ^= 1;
    }
    return ret;
}
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int ans = -1 << 20;
    rep(i, n)
    {
        int cur = -1 << 20;
        int ind = -1;
        rep(j, n)
        {
            if (i == j)
                continue;
            int ret = score(v, i, j, false);
            if (ret > cur)
            {
                cur = ret;
                ind = j;
            }
        }
        int ret = score(v, i, ind, true);
        ans = max(ans, ret);
    }
    cout << ans << endl;
    return 0;
}