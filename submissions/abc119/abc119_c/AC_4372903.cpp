#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
#define ALL(x) x.begin(), x.end()
#define fir first
#define sec second
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int t[n], g[n] = {};
    rep(i, n) cin >> t[i];
    ll ans = 1ll << 20;
    rep(i, (int)pow(4, n))
    {
        int p[3] = {0, 0, 0};
        ll now = 0;
        rep(j, n)
        {
            if (g[j] == 3)
                continue;
            int ind = g[j];
            if (p[ind] != 0)
                now += 10;
            p[ind] += t[j];
        }
        if (p[0] == 0)
            now = 1ll << 20;
        else
            now += abs(a - p[0]);
        if (p[1] == 0)
            now = 1ll << 20;
        else
            now += abs(b - p[1]);
        if (p[2] == 0)
            now = 1ll << 20;
        else
            now += abs(c - p[2]);
        ans = min(ans, now);
        //  cout << now << endl;
        g[n - 1]++;
        int ii = n - 1;
        while (g[ii] == 4)
        {
            g[ii] = 0;
            g[ii - 1]++;
            ii--;
        }
    }
    cout << ans << endl;

    return 0;
}