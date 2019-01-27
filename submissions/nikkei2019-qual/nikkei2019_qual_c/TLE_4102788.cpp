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
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back(pair<ll, ll>{a, b});
    }
    ll ans = 0;
    bool takahashi = true;
    while (!v.empty())
    {
        auto am = max_element(ALL(v), cmp);
        auto bm = max_element(ALL(v), cmp);
        if (takahashi)
        {
            if ((*am).fir < (*bm).sec)
            {
                ans += (*bm).first;
                v.erase(bm);
            }
            else
            {
                ans += (*am).first;

                v.erase(am);
            }
        }
        else
        {
            if ((*am).fir < (*bm).sec)
            {
                ans -= (*bm).second;
                v.erase(bm);
            }
            else
            {
                ans -= (*am).second;

                v.erase(am);
            }
        }
        takahashi = !takahashi;
        }
    cout << ans << endl;
    return 0;
}