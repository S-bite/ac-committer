#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
struct island
{
    ll s, e;
    ll amount, scost, tcost;
};

int main()
{
    ll l;
    cin >> l;
    ll a[l];
    ll start = -1, end = -1;
    bool zerof = false;
    ll scost = 0, bcost = 0;
    ll ans = 0;
    rep(i, l) cin >> a[i];
    int i = 0;
    while (a[i] == 0)
        i++;

    while (true)
    {
        ll old = i;
        while (a[i] != 0)
        {
            scost += a[i];
            i++;
            if (i == l)
                break;
        }
        if (i == l)
            break;

        while (a[i] == 0)
        {
            bcost++;
            i++;
            if (i == l)
                break;
        }
        if (i == l)
            break;
        if (bcost < scost)
        {
            for (ll j = old; j != i; j++)
            {
                if (a[j] == 0)
                {
                    a[j] = 1;
                    ans++;
                }
            }
        }
        else
        {
            for (ll j = old; j != i; j++)
            {
                if (a[j] != 0)
                {
                    ans += a[j];
                    a[j] = 0;
                }
            }
        }
    }

    // cout << ":" << endl;
    // rep(i, l) cout << a[i] << endl;
    // cout << "ans:" << ans << endl;

    i = 0;
    while (a[i] == 0)
        i++;
    start = i;

    for (ll i = start; i < l; i++)
    {
        if (a[i] % 2 == 0 and a[i] != 0)
            ans++;
        if (a[i] != 0)
            end = i;
        //  cout << end << endl;
    }
    //cout << a[start] << endl;
    //cout << a[end] << endl;

    ll nowscore = 0;
    ll maxscore = -1;
    for (ll i = start; i != end; i++)
    {
        if (a[i] % 2 == 0)
        {
            nowscore++;
        }
        else
        {
            nowscore--;
        }
        maxscore = max(maxscore, nowscore);
    }
    nowscore = 0;
    for (ll i = end; i != start; i--)
    {
        if (a[i] % 2 == 0)
        {
            nowscore++;
        }
        else
        {
            nowscore--;
        }
        maxscore = max(maxscore, nowscore);
        //  cout << "maxscore:" << maxscore << endl;
    }
    cout << ans - maxscore << endl;
    return 0;
}