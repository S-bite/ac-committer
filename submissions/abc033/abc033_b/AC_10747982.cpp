#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> p(n);
    int sum = 0;
    rep(i, n)
    {
        cin >> p[i].second >> p[i].first;
        sum += p[i].first;
    }
    sort(ALL(p));
    string ans = "atcoder";
    rep(i, n)
    {
        if (p[i].first * 2 > sum)
            ans = p[i].second;
    }
    cout << ans << endl;
    return 0;
}