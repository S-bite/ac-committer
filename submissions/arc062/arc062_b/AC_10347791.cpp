#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int cur = 0;
    int ans = 0;
    rep(i, s.size())
    {
        if (cur > 0)
        {
            cur--;

            if (s[i] == 'g')
            {
                ans++;
            }
        }
        else
        {
            cur++;
            if (s[i] == 'p')
            {
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
