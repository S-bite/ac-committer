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
int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> robot(n);
    rep(i, n) cin >> robot[i].first >> robot[i].second;
    sort(ALL(robot));
    ll ans = 1;
    ll last = 0;
    rep(i, 1, n)
    {
        ll a = robot[last].first + robot[last].second;
        ll b = robot[i].first - robot[i].second;
        if (a > b)
        {
            b = robot[i].first + robot[i].second;
            if (b < a)
            {
                last = i;
            }
        }
        else
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
