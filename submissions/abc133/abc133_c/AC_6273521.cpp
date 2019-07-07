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
    ll l, r;
    cin >> l >> r;
    if (r - l + 1 >= 2019)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> v;
    rep(i, l, r + 1)
    {
        v.push_back(i % 2019);
    }
    int ans = 2020;
    rep(i, v.size())
    {
        rep(j, i + 1, v.size())
        {

            ans = min(ans, (v[i] * v[j]) % 2019);
        }
    }
    cout << ans << endl;

    return 0;
}
