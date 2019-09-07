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
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n)
    {
        cin >> b[i];
    }

    rep(i, n - 1) cin >> c[i];
    int ans = 0;
    int prev = -2;
    rep(i, n)
    {
        ans += b[a[i]];
        if (prev + 1 == a[i])
        {
            ans += c[prev];
        }
        prev = a[i];
    }
    cout << ans << endl;
    return 0;
}
