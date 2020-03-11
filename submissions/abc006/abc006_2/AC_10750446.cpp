#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const int MOD = 10007;

int main()
{
    int n;
    cin >> n;
    n--;
    vector<int> a(1010101);
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    rep(i, 3, 1010101)
    {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        a[i] %= MOD;
    }
    cout << a[n] << endl;
    return 0;
}