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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int x1 = 0, x2 = 0;
    int ans = 0;
    rep(i, n - 1)
    {
        if (s[i] != s[i + 1])
        {
            x2++;
        }
        else
        {
            ans++;
        }
    }

    if (k <= x2)
    {
        ans += 2 * k;
    }
    else
    {
        ans += 2 * x2;
        k -= x2;
        ans += min(2, k);
    }
    cout << ans << endl;
    return 0;
}
