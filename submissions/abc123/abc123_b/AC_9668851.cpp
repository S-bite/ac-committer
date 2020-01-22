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
    vector<int> v(5);
    rep(i, 5) cin >> v[i];
    sort(ALL(v));
    int ans = 1 << 30;

    rep(i, 5)
    {
        int tmp = 0;
        rep(j, 5)
        {
            if (j == i)
            {
                tmp += v[j];
            }
            else
            {
                tmp += ((v[j] + 9) / 10) * 10;
            }
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
