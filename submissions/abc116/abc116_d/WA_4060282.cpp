#include <bits/stdc++.h>
#define ll unsigned long long
#define fir first
#define sec second
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    pair<ll, ll> sushi[n + 1];
    pair<ll, ll> maxsushi[n + 10];
    for (int i = 0; i <= n; i++)
        maxsushi[i + 1] = pair<ll, ll>{0, i + 1};
    for (int i = 0; i < n; i++)
    {
        ll t, d;
        cin >> t >> d;
        maxsushi[t] = max(maxsushi[t], pair<ll, ll>{d, t});
        // cout << "lp:" << maxsushi[t].sec << "," << maxsushi[t].fir << endl;
        sushi[i] = pair<ll, ll>{d, t};
    }

    // cout << "s" << endl;
    sort(sushi, sushi + n + 1, greater<pair<ll, ll>>());
    sort(maxsushi, maxsushi + n + 1, greater<pair<ll, ll>>());
    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << maxsushi[i].sec << "," << maxsushi[i].fir << endl;
    //  }
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ll sum = 0, count = 0;
        bool used[n];
        for (int j = 0; j < n; j++)
            used[j] = false;
        for (int j = 0; j < i; j++)
        {
            if (maxsushi[j].fir == 0)
            {
                count = k + 1;
                break;
            }
            sum += maxsushi[j].fir;
            used[maxsushi[j].sec] = true;
            count++;
        }
        bool used2[n];
        for (int j = 0; j < n; j++)
            used2[j] = false;

        for (int j = 0; j < n; j++)
        {

            if (count >= k)
                break;
            //   cout << "dbg:" << sushi[j].sec << "," << sushi[j].fir << endl;
            if (used[sushi[j].sec])
            {
                if (used2[sushi[j].sec] == false)
                {
                    //      cout << "max" << endl;
                    used2[sushi[j].sec] = true;
                    continue;
                }
                else
                {
                    //     cout << "accept" << endl;
                    sum += sushi[j].fir;
                    count++;
                }
            }
        }
        //  cout << i << "," << count << "," << sum << endl;
        if (count != k)
            break;
        ans = max(ans, sum + (ll)i * (ll)i);
    }

    cout << ans << endl;
    return 0;
}