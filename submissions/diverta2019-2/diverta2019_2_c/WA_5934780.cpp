#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    ll a[n];
    ll ans = 0;

    rep(i, n)
    {
        cin >> a[i];
        ans += abs(a[i]);
    }
    sort(a, a + n, greater<ll>());
    if (a[n - 1] > 0)
        ans -= 2 * a[n - 1];
    cout << ans << endl;

    if (n == 2)
    {
        cout << a[0] << " " << a[1] << endl;
        return 0;
    }

    ll now = 0;
    cout << a[n - 1] << " " << a[n - 2] << endl;
    ;
    now = a[n - 1] - a[n - 2];
    rep(i, 3, n)
    {

        ll x = now - a[n - i];

        if (x < 0)
        {
            cout << now << " " << a[n - i] << endl;
            now = now - a[n - i];
        }
        else
        {

            cout << a[n - i] << " " << now << endl;
            now = a[n - i] - now;
        }
    }
    cout << a[0] << " " << now << endl;
    return 0;
}
