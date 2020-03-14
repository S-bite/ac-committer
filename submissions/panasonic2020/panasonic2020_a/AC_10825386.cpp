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

int main()
{
    vector<int> v = {1,
                     1,
                     1,
                     2,
                     1,
                     2,
                     1,
                     5,
                     2,
                     2,
                     1,
                     5,
                     1,
                     2,
                     1,
                     14,
                     1,
                     5,
                     1,
                     5,
                     2,
                     2,
                     1,
                     15,
                     2,
                     2,
                     5,
                     4,
                     1,
                     4,
                     1,
                     51};
    int k;
    cin >> k;
    cout << v[k - 1] << endl;

    return 0;
}