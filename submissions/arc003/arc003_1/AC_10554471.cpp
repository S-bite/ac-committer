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
    int sum = 0;
    string s;
    cin >> s;
    rep(i, n)
    {
        sum += max(0, 4 - (s[i] - 'A'));
    }
    cerr << sum << endl;
    cout << fixed << setprecision(18) << (lld)((lld)sum / n) << endl;
    return 0;
}
