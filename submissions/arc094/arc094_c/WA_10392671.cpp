#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    ll minnum = 1ll << 60;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        sum += a;
        if (a < b)
            minnum = min(minnum, (ll)a);
    }
    cout << sum - minnum << endl;
    return 0;
}
