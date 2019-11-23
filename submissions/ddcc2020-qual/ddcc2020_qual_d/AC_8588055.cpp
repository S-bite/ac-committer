#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int main(int argc, char const *argv[])
{
    ll m;
    cin >> m;
    ll d[m];
    ll c[m];
    ll ans = 0;
    rep(i, m) cin >> d[i] >> c[i];
    ll digitsum = 0;
    ll length = 0;
    rep(i, m)
    {
        digitsum += d[i] * c[i];
        length += c[i];
    }
    cout << (digitsum - 1) / 9 + length - 1 << endl;
    return 0;
}
