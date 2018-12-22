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
    cin >> now;
    rep(i, n - 1)
    {
        cin >> next;
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
        }
    }
    cout << ans << endl;
    return 0;
}
