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
    ll prev = -20e9;
    ll now, next;
    ll k = 1;
    cin >> now;
    rep(i, n - 1)
    {
        cin >> next;
        next /= k;
        if (now <= next)
        {
            prev = now;
            now = next;
            continue;
        }
        if (prev <= -2 * now)
        {
            ans++;
            now *= -2;
            prev = now;
            now = next;
            if (now > (ll)10e16)
            {
                k *= 10;
                now /= k;
                prev / k;
            }
        }
        else
        {
            while (next < now)
            {
                next *= 4;
                ans += 2;
            }
            prev = now;
            now = next;
            if (now > (ll)10e16)
            {
                k *= 10;
                now /= k;
                prev / k;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
