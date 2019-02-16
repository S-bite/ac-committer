#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
ll f(ll a, ll b)
{
    ll x = max(a, b), y = min(a, b);
    if (x % y == 0)
        return y;
    return f(y, x % y);
}

int main()
{
    ll ans = 1ll << 30;
    int n, a;
    cin >> n;
    cin >> a;
    ans = a;
    n--;
    rep(i, n)
    {
        int b;
        cin >> b;
        ans = f(b, ans);
    }
    cout << ans << endl;
    return 0;
}