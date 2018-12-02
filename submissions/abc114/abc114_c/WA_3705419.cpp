#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;
ll next(ll i)
{
    ll div = 1;
    while (i / div != 0)
    {
        int d = (i / div) % 10;
        while (d != 3 and d != 5 and d != 7)
        {
            i += div;
            d = (i / div) % 10;
        }
        div *= 10;
    }
    return i;
}
bool is753(int n)
{
    bool in7 = false, in5 = false, in3 = false;
    do
    {
        if (n % 10 == 7)
            in7 = true;
        else if (n % 10 == 5)
            in5 = true;
        else if (n % 10 == 3)
            in3 = true;
        else
            return false;
        n /= 10;
    } while (n != 0);
    return in7 && in5 && in3;
}
int main()
{
    ll n, ans = 0;
    cin >> n;
    if (n < 357)
    {
        cout << 0 << endl;
        return 0;
    }
    for (ll i = 0; i <= n; i++)
    {
        i = next(i);

        if (is753(i))
        {
            ans++;
            // cout << i << endl;
        }
        //cout << i << endl;
    }
    cout << ans << endl;
    return 0;
}