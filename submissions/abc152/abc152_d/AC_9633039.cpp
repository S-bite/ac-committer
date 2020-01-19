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
int head(int n)
{
    while (n > 9)
    {
        n /= 10;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int c[10][10];
    rep(i, 10) rep(j, 10) c[i][j] = 0;
    rep(i, 1, n + 1)
    {
        c[head(i)][i % 10]++;
    }
    ll ans = 0;
    rep(i, 10) rep(j, 10)
    {
        ans += c[i][j] * c[j][i];
    }
    cout << ans << endl;
    return 0;
}
