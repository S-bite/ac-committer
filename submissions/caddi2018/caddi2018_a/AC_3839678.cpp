#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
using namespace std;
int main()
{
    ll n, p;
    cin >> n >> p;
    if (n == 1)
    {
        cout << p << endl;
        return 0;
    }
    ll ans, i = 1;

    while (powl(i, n) <= p)
    {
        if (p % (ll)(powl(i, n)) == 0)
            ans = i;
        i++;
    }
    cout << ans << endl;
    return 0;
}
