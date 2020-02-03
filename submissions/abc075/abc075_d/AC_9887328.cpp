#include <bits/stdc++.h>
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
ll check(vector<pair<ll, ll>> &ps, int k, ll sx, ll sy, ll ex, ll ey)
{
    ll area = abs(sx - ex) * abs(sy - ey);
    //assert(area > 0);
    if (area == 0)
        return -1;
    int cur = 0;
    for (auto p : ps)
    {
        if (sx <= p.first && p.first <= ex && sy <= p.second && p.second <= ey)
            cur++;
    }
    return (cur >= k ? area : -1);
}
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> ps(n);
    rep(i, n) cin >> ps[i].first >> ps[i].second;
    ll ans = (1ll << 62);
    rep(i1, n)
    {
        rep(i2, n)
        {
            rep(i3, n)
            {

                rep(i4, n)
                {
                    ll ret;
                    ret = check(ps, k, ps[i1].first, ps[i2].second, ps[i3].first, ps[i4].second);
                    if (ret != -1)
                    {
                        ans = min(ans, ret);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
