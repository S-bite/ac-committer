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
    int n, l;
    cin >> n >> l;

    int sum = 0;
    int ans = 101010;

    rep(i, n)
    {
        sum += l + (int)i;
    }
    rep(i, n)
    {
        if (abs(ans) > abs(l + (int(i))))
        {
            ans = l + i;
        }
    }
    cout << sum - ans << endl;
    return 0;
}
