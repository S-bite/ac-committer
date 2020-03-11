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
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    rep(i, n)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % n != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int avg = sum / n;
    cerr << avg << endl;
    int ans = 0;
    rep(i, n)
    {
        int cur = v[i];
        int t = 1;
        cerr << i << endl;
        while (cur / t != avg)
        {
            i++;
            cur += v[i];
            ans++;
            t++;
            cerr << "con " << i << " t " << t << " cur " << cur << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
