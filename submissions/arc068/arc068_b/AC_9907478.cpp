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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;
    rep(i, n)
    {
        mp[a[i]]++;
    }
    int ans = 0;
    int two = 0, one = 0;
    for (auto x : mp)
    {
        cerr << x.first << " " << x.second << endl;
        ans += (x.second - 1) / 2;
        if (2 - (x.second % 2) == 2)
        {
            two++;
        }
        else
        {
            one++;
        }
    }
    ans += two / 2;
    if (two % 2 == 1)
        ans++;
    cout << n - 2 * ans << endl;
    return 0;
}
