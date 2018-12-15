#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    int ans = h;
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        if (x - 1 > y)
        {
            ans = min(ans, x);
            // if (x > y - 1)
            //    ans = min(ans, x - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
