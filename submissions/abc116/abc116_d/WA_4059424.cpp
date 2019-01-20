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

    priority_queue<pair<int, int>> sushi;
    for (int i = 0; i < n; i++)
    {
        int t, d;
        cin >> t >> d;
        sushi.push(pair<int, int>{d, t});
    }
    pair<int, int> sushiset[k];
    map<int, int> sushimap;

    for (int i = 0; i < k; i++)
    {
        sushiset[i] = sushi.top();
        sushimap[sushi.top().sec]++;
        sushi.pop();
    }

    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += sushiset[i].fir;
    }
    ans += (ll)sushimap.size() * sushimap.size();
    while (!sushi.empty())
    {
        pair<int, int> altsushi = sushi.top();
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
    }
    cout << ans << endl;
    return 0;
}