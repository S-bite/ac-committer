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
    ll n, k, s;
    cin >> n >> k >> s;
    ll dummy;
    if (s == 1e9)
    {
        dummy = s - 1;
    }
    else
    {
        dummy = s + 1;
    }
    rep(i, k)
    {
        cout << s << " ";
    }
    rep(i, n - k)
    {
        cout << dummy << " ";
    }
    cout << endl;
    return 0;
}
