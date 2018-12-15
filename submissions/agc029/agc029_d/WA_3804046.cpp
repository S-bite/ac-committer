#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    int ans = w - 1;
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        if (x - 1 > y)
        {
            ans = min(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}
