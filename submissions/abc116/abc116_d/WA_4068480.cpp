#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9 + 7)

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<pll> dt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dt[i].second >> dt[i].first;
    }

    sort(dt.begin(), dt.end());
    reverse(dt.begin(), dt.end());
    //寿司は価値，種類の順に管理

    map<ll, ll> eat;
    ll val = 0; //食べた寿司の価値
    //価値の高い順にk個食べるとする，種類と食べた数をmapで管理
    for (int i = 0; i < k; i++)
    {
        eat[dt[i].second]++;
        val += dt[i].first;
    }
    ll pd = k;
    ll pu = k - 1;
    ll diverse = ll(eat.size()); //現在の種類数

    ll ans = val + diverse * diverse;
    while (pu != -1 && pd != n)
    {
        while (eat.find(dt[pd].second) != end(eat))
        { //食べてない種類の寿司で価値の高いものを食べる
            pd++;
        }
        while ((eat.find(dt[pu].second) == end(eat)))
        { //2個以上食べた種類で価値の低いものを捨てる
            pu--;
        }
        if (pu == -1 || pd == n)
        {
            break;
        }
        val += dt[pd].first;
        eat[dt[pd].second]++;
        val -= dt[pu].first;
        eat[dt[pu].second]--;
        diverse++;
        ans = max(ans, val + diverse * diverse);
    }
    cout << ans << endl;

    return 0;
}
