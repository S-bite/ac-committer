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
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    int x[n], y[n];
    rep(i, n)
    {
        if (i < n / 2)
            ans -= a[i];
        else
            ans += a[i];
    }
    cout << ans << endl;
    if (n % 2 == 0)
    {
        cout << a[0] << " " << a[n - 1] << endl;
        ;
        ll st = a[0] - a[n - 1];
        rep(i, n / 2)
        {
            cout << a[i + 1] << " " << st << endl;
            st = a[i + 1] - st;
        }
    }
    else
    {
        cout << a[0] << " " << a[n - 1] << endl;
        ll st = a[0] - a[n - 1];
        rep(i, n / 2)
        {
            cout << a[i + 1] << " " << st << endl;
            st = a[i + 1] - st;
        }
    }

    return 0;
}
