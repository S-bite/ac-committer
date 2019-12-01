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
    int x;
    cin >> x;
    vector<bool> dp(x + 1, false);
    dp[0] = true;
    rep(i, 6)
    {
        rep(j, x + 1)
        {
            if (j + 100 + i > x)
            {
                break;
            }
            if (dp[j] == true)
            {
                dp[j + 100 + i] = true;
            }
        }
    }
    if (dp[x] == true)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
