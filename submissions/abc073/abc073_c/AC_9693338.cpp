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
    vector<bool> v(1e9, false);
    int n;
    cin >> n;
    int ans = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        a--;
        if (v[a] == false)
        {
            ans++;
            v[a] = true;
        }
        else
        {
            ans--;
            v[a] = false;
        }
    }
    cout << ans << endl;
    return 0;
}
