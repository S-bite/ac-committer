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
const long long INF = 1LL << 60;
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int p[n];
    rep(i, n) cin >> p[i];
    int pp[n];
    rep(i, n) pp[p[i] - 1] = i + 1;
    int a[n];
    a[0] = pp[0];
    rep(i, 1, n)
    {
        a[i] = a[i - 1] + pp[i];
    }
    int b[n];
    b[0] = a[n - 1];
    rep(i, 1, n)
    {
        b[i] = b[i - 1] - pp[i - 1];
    }
    rep(i, n) cout << a[i] << " ";
    cout << endl;

    rep(i, n) cout << b[i] << " ";
    cout << endl;
    return 0;
}
