#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    pair<int, int> sushi[n];
    for (int i = 0; i < n; i++)
    {
        int t, d;
        cin >> t >> d;
        sushi[i] = pair<int, int>{d, t};
    }
    sort(sushi, sushi + n, greater<pair<int, int>>());
    pair<int, int> gsushi[k];
    map<int, int> mp;
    int ntype = 0;
    for (int i = 0; i < k; i++)
    {
        gsushi[i].fir = sushi[i].fir;
        gsushi[i].sec = sushi[i].sec;
        if (mp[sushi[i].sec] == 0)
            ntype++;
        mp[sushi[i].sec]++;
    }
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += gsushi[i].fir;
    }
    ans += ntype * ntype;

    bool end = false;
    for (int i = k; i < n; i++)
    {
        if (mp[sushi[i].sec] == 0)
        {
            for (int j = k - 1; j >= 0; j--)
            {
                if (mp[gsushi[j].sec] > 1)
                {

                    mp[gsushi[j].sec] -= 1;
                    gsushi[j].fir = sushi[i].fir;
                    gsushi[j].sec = sushi[i].sec;
                    mp[gsushi[j].sec] = 1;
                    ntype++;

                    ll tans = 0;
                    for (int ii = 0; ii < k; ii++)
                    {
                        tans += gsushi[ii].fir;
                    }
                    tans += ntype * ntype;
                    ans = max(ans, tans);
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}