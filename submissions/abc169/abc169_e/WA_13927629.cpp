#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    if (n % 2 == 1)
    {
        cout << b[n / 2] - a[n / 2] + 1 << endl;
    }
    else
    {
      	int ma=a[n/2]+a[n/2-1];
      	int mb=b[n/2]+b[n/2-1];
        cout << 2*(mb-ma)-1 << endl;
    }

    return 0;
}