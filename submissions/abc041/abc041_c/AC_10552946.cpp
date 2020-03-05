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
    vector<pair<int, int>> p(n);
    rep(i, n)
    {
        cin >> p[i].first;
        p[i].first *= -1;
        p[i].second = i;
    }
    sort(ALL(p));
    rep(i, n)
    {
        cout << p[i].second + 1 << endl;
    }
    return 0;
}