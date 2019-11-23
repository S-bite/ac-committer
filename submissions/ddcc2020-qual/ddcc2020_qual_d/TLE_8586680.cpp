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
    ll last = 0;
    ll carry = 0;
    rep(i, m)
    {
        ans += c[i] - 1;
        if (i != 0)
            ans++;

        carry += (c[i] * d[i] + last) / 10;
        last = (c[i] * d[i] + last) % 10;
        //cerr << i << " " << ans << " " << last << " " << carry << endl;
    }
    //cerr << carry << endl;
    ans += carry;
    last += carry;
    while (last > 9)
    {
        ans++;
        last -= 9;
    }
    cout << ans << endl;
    return 0;
}
