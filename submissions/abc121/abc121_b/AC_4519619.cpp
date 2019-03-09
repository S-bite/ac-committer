#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, c;
    cin >> n >> m >> c;
    int b[m];
    rep(i, m) cin >> b[i];
    int ans = 0;
    rep(i, n)
    {
        int ret = c;
        rep(j, m)
        {
            int t;
            cin >> t;
            ret += b[j] * t;
        }
        if (ret > 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
