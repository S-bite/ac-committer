#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll unsigned long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main(int argc, char const *argv[])
{
    int n, a, b;
    cin >> n >> a >> b;
    ll v[n];
    rep(i, n) cin >> v[i];
    sort(v, v + n, greater<ll>());
    rep(i, n) dumpl(v[i]);

    ll target = 0;
    rep(i, a) target += v[i];
    map<ll, ll> mp[n + 1], _mp[n + 1];
    mp[0][0] = 1;
    rep(i, n)
    {
        ll t = v[i];
        //cout << t << endl;
        rep(j, n + 1)
            _mp[j] = mp[j];
        rep(j, i + 1)
        {

            for (auto item : _mp[j])
            {
                auto key = item.first;
                if ((key + t) * a <= target * (j + 1))
                    mp[j + 1][key + t] += _mp[j][key];
            }
        }
        rep(j, i)
        {

            for (auto item : mp[j])
            {
                dump(j);
                dump(item.first);
                dumpl(mp[j][item.first]);
            }
        }
    }
    ll pattern = 0;
    rep(i, a, b + 1)
    {
        if (target * i % a != 0)
            continue;
        pattern += mp[i][target * i / a];
    }
    cout << (lld)target / a << endl;
    cout << pattern << endl;

    return 0;
}
