#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
int main()
{
    string s;
    cin >> s;
    ll t = 0, n = s.size(), ans = 0;

    rep(i, n)
    {

        if (s[i] == 'B')
        {
            t++;
        }
        else
        {
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}