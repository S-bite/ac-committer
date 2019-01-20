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

    priority_queue<pair<ll, ll>> sushi;
    for (int i = 0; i < n; i++)
    {
        ll t, d;
        cin >> t >> d;
        sushi.push(pair<ll, ll>{d, t});
    }
    pair<ll, ll> sushiset[k];
    map<ll, ll> sushimap;

    for (int i = 0; i < k; i++)
    {
        sushiset[i] = sushi.top();
        sushimap[sushi.top().sec]++;
        sushi.pop();
    }
    sort(sushiset, sushiset + k, greater<pair<ll, ll>>());

    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += sushiset[i].fir;
    }
    ans += (ll)sushimap.size() * sushimap.size();
    while (!sushi.empty())
    {
        pair<ll, ll> altsushi = sushi.top();
        sushi.pop();
        if (sushimap.find(altsushi.sec) == end(sushimap))
        {
            for (int i = k - 1; i >= 0; i--)
            {
                if (sushimap[sushiset[i].sec] > 1)
                {
                    sushimap[sushiset[i].sec]--;
                    sushiset[i] = altsushi;
                    sushimap[sushiset[i].sec]++;
                    ll tans = 0;
                    for (int j = 0; j < k; j++)
                    {
                        tans += sushiset[j].fir;
                    }
                    tans += (ll)sushimap.size() * sushimap.size();
                    ans = max(ans, tans);
                }
            }
        }
        sort(sushiset, sushiset + k, greater<pair<ll, ll>>());
    }
    cout << ans << endl;
    return 0;
}