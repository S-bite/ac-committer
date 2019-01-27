#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define MOD (1000000007ll)
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    rep(i, n)
    {
        if (a[i] == b[i] && b[i] == c[i])
            ans += 0;
        else if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i])
            ans += 1;
        else
            ans += 2;
    }
    cout << ans << endl;
    return 0;
}