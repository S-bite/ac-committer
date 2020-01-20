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
    int sumtime = 0;
    vector<int> v(n);
    rep(i, n)
    {
        int t;
        cin >> t;
        v[i] = t;
        sumtime += t;
    }
    int m;
    cin >> m;
    rep(i, m)
    {
        int p, x;
        cin >> p >> x;
        p--;
        cout << sumtime - v[p] + x << endl;
    }
    return 0;
}
