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
    vector<pair<ll, ll>> v(n);
    rep(i, n)
    {
        cin >> v[i].second >> v[i].first;
    }
    sort(ALL(v));
    ll cur = 0;
    int ans = 0;
    rep(i, n)
    {
        if (cur + v[i].second <= v[i].first)
        {
            cur += v[i].second;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}