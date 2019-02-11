#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define fir first
#define sec second
using namespace std;

int main()
{
    int n;
    cin >> n;

    pair<int, int> p[n];
    rep(i, n) cin >> p[i].fir >> p[i].sec;
    int dis[n][n];
    rep(i, n) for (int j = i + 1; j < n; j++)
    {
        dis[i][j] = (p[i].fir - p[j].fir) * (p[i].fir - p[j].fir) + (p[i].sec - p[j].sec) * (p[i].sec - p[j].sec);
        dis[j][i] = dis[i][j];
    }
    ll mcost = 0;
    rep(i, n) rep(j, n)
    {
        mcost += (ll)dis[i][j];
    }
    mcost /= n * n;
    map<int, bool> mp;
    cout << 0 << endl;
    mp[0] = true;
    int now = 0;
    rep(i, n - 1)
    {
        ll diff = 1ll << 30;
        int next;
        rep(j, n)
        {
            if (mp[j] == true)
            {
                continue;
            }
            if (abs(dis[now][j] - mcost) < diff)
            {
                diff = abs(dis[now][j] - mcost);
                next = j;
            }
        }
        cout << next << endl;
        mp[next] = true;
        now = next;
    }
    return 0;
}