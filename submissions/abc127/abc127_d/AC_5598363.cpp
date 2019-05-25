#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    pair<int, int> p[m];
    rep(i, m)
    {
        int b, c;
        cin >> b >> c;
        p[i] = {c, b};
    }
    sort(p, p + m, greater<pair<int, int>>());
    int ind = 0;
    bool f = false;
    rep(i, m)
    {
        rep(j, p[i].second)
        {
            if (ind == n)
            {
                f = true;
                break;
            }
            if (a[ind] < p[i].first)
            {
                a[ind] = p[i].first;
            }
            else
            {
                f = true;
                break;
            }
            ind++;
        }
        if (f == true)
        {
            break;
        }
    }
    rep(i, n)
    {
        //cerr << a[i] << endl;
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
