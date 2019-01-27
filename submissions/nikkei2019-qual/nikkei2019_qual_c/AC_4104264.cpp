#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define MOD (1000000007ll)
#define ALL(x) x.begin(), x.end()
using namespace std;
bool cmp(const pair<ll, ll> &first, const pair<ll, ll> &second)
{
    return first.second < second.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    ll all = 0;
    ll t[n];
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        all += a;
        t[i] = a + b;
    }
    sort(t, t + n, greater<ll>());
    ll ans = all;
    rep(i, n)
    {
        if (i % 2 == 0)
            continue;
        ans -= t[i];
    }
    cout << ans << endl;
    return 0;
}