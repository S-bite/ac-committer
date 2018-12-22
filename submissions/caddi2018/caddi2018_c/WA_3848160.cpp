#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll a[n + 2];
    a[0] = -20e9;
    a[n + 1] = 10e17;
    rep(i, n) cin >> a[i + 1];

    for (ll i = 1; i <= n; i++)
    {

        if (a[i] <= a[i + 1])
        {
            continue;
        }
        else if (a[i - 1] <= -2 * a[i])
        {
            ans++;
            a[i] *= -2;
        }
        else
        {
            while (a[i] > a[i + 1])
            {
                a[i + 1] *= 4;
                ans += 2;
            }
        }
        if (a[i] < -10e16 or a[i + 1] > 10e16)
        {
            rep(j, n + 1) a[j] /= 100;
        }
    }

    cout << ans << endl;
    return 0;
}
