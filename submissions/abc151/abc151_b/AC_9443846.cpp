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
    int n, k, m;
    cin >> n >> k >> m;
    int sum = 0;
    rep(i, n - 1)
    {
        int t;
        cin >> t;
        sum += t;
    }
    int bb = m * n - sum;
    if (bb < 0)
    {
        bb = 0;
    }
    if (bb > k)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << bb << endl;
    }
    return 0;
}