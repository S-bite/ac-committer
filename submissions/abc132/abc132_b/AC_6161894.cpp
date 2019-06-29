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

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    rep(i, n) cin >> v[i];
    int ans = 0;
    rep(i, 1, n - 1)
    {
        vector<int> v2 = {v[i - 1], v[i], v[i + 1]};
        sort(v2.begin(), v2.end());
        if (v2[1] == v[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}