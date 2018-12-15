#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
ll targetnum(ll n)
{
    ll ret = 1ll << (ll)floor(log2(n * 2));
    return ret;
}

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    map<ll, ll> mp;
    rep(i, n)
    {
        ll t;
        cin >> t;
        a[i] = t;
        mp[t]++;
    }
    sort(a, a + n, greater<ll>());
    ll ans = 0;
    rep(i, n)
    {
        ll t = targetnum(a[i]) - a[i];
        if (mp[t] > 0 + (t == a[i] ? 1 : 0))
        {
            ans++;
            mp[t]--;
            mp[a[i]]--;
        }
    }

    cout << ans << endl;
    return 0;
}